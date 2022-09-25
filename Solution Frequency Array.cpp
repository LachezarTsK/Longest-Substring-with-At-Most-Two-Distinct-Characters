
#include <string>
#include <vector>
using namespace std;

class Solution {
    
public:
    int lengthOfLongestSubstringTwoDistinct(string input) {
        if (input.length() < 3) {
            return input.length();
        }

        int ascii_codePointDifference = 'z' - 'A';
        vector<int> frequency(ascii_codePointDifference + 1);

        int maxSubstringWithAtMostTwoDistinctChars = 0;
        int numberOdDistinctChars = 0;
        int leftPointer = 0;
        int rightPointer = 0;

        while (rightPointer < input.length()) {
            char currentChar = input[rightPointer];
            numberOdDistinctChars += (frequency[currentChar - 'A'] == 0) ? 1 : 0;
            ++frequency[currentChar - 'A'];
            ++rightPointer;

            if (numberOdDistinctChars < 3) {
                maxSubstringWithAtMostTwoDistinctChars = max(maxSubstringWithAtMostTwoDistinctChars, rightPointer - leftPointer);
                continue;
            }

            //boundary checking is not necessary: at this point there are 3 distinct chars.
            while (--frequency[input[leftPointer] - 'A'] > 0) {
                ++leftPointer;
            }
            ++leftPointer;
            --numberOdDistinctChars;

        }
        return maxSubstringWithAtMostTwoDistinctChars;
    }
};
