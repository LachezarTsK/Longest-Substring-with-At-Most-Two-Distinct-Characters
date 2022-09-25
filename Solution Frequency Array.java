
public class Solution {

    public int lengthOfLongestSubstringTwoDistinct(String input) {
        if (input.length() < 3) {
            return input.length();
        }

        int ascii_codePointDifference = 'z' - 'A';
        int[] frequency = new int[ascii_codePointDifference + 1];

        int maxSubstringWithAtMostTwoDistinctChars = 0;
        int numberOdDistinctChars = 0;
        int leftPointer = 0;
        int rightPointer = 0;

        while (rightPointer < input.length()) {
            char currentChar = input.charAt(rightPointer);
            numberOdDistinctChars += (frequency[currentChar - 'A'] == 0) ? 1 : 0;
            ++frequency[currentChar - 'A'];
            ++rightPointer;

            if (numberOdDistinctChars < 3) {
                maxSubstringWithAtMostTwoDistinctChars = Math.max(maxSubstringWithAtMostTwoDistinctChars, rightPointer - leftPointer);
                continue;
            }

            //boundary checking is not necessary: at this point there are 3 distinct chars.
            while (--frequency[input.charAt(leftPointer) - 'A'] > 0) {
                ++leftPointer;
            }
            ++leftPointer;
            --numberOdDistinctChars;

        }
        return maxSubstringWithAtMostTwoDistinctChars;
    }
}
