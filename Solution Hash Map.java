
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public int lengthOfLongestSubstringTwoDistinct(String input) {
        if (input.length() < 3) {
            return input.length();
        }

        Map<Character, Integer> charToLastIndex = new HashMap<>();
        int maxSubstringWithAtMostTwoDistinctChars = 0;
        int leftPointer = 0;
        int rightPointer = 0;

        while (rightPointer < input.length()) {
            char currentChar = input.charAt(rightPointer);
            charToLastIndex.put(currentChar, rightPointer);
            ++rightPointer;

            if (charToLastIndex.size() == 3) {
                char charToRemove = input.charAt(Collections.min(charToLastIndex.values()));
                leftPointer = charToLastIndex.get(charToRemove) + 1;
                charToLastIndex.remove(charToRemove);
            }
            maxSubstringWithAtMostTwoDistinctChars = Math.max(maxSubstringWithAtMostTwoDistinctChars, rightPointer - leftPointer);
        }
        return maxSubstringWithAtMostTwoDistinctChars;
    }
}
