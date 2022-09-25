
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    
public:
    int lengthOfLongestSubstringTwoDistinct(string input) {
        if (input.length() < 3) {
            return input.length();
        }

        unordered_map<char, int> charToLastIndex;
        int maxSubstringWithAtMostTwoDistinctChars = 0;
        int leftPointer = 0;
        int rightPointer = 0;

        while (rightPointer < input.length()) {
            char currentChar = input[rightPointer];
            charToLastIndex[currentChar] = rightPointer;
            ++rightPointer;

            if (charToLastIndex.size() == 3) {
                static constexpr auto comparator = [](const auto& x, const auto& y) { return x.second < y.second; };

                //C++20: charToRemove = input[std::ranges::min_element(charToLastIndex,comparator)->second];
                char charToRemove = input[min_element(charToLastIndex.begin(), charToLastIndex.end(), comparator)->second];

                leftPointer = charToLastIndex[charToRemove] + 1;
                charToLastIndex.erase(charToRemove);
            }
            maxSubstringWithAtMostTwoDistinctChars = max(maxSubstringWithAtMostTwoDistinctChars, rightPointer - leftPointer);
        }
        return maxSubstringWithAtMostTwoDistinctChars;
    }
};
