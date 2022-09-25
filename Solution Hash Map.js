
/**
 * @param {string} input
 * @return {number}
 */
var lengthOfLongestSubstringTwoDistinct = function (input) {
    if (input.length < 3) {
        return input.length;
    }

    const charToLastIndex = new Map();//Map<Character, Integer>
    let maxSubstringWithAtMostTwoDistinctChars = 0;
    let leftPointer = 0;
    let rightPointer = 0;

    while (rightPointer < input.length) {
        let currentChar = input.charAt(rightPointer);
        charToLastIndex.set(currentChar, rightPointer);
        ++rightPointer;

        if (charToLastIndex.size === 3) {
            let charToRemove = input.charAt(Math.min(...charToLastIndex.values()));
            leftPointer = charToLastIndex.get(charToRemove) + 1;
            charToLastIndex.delete(charToRemove);
        }
        maxSubstringWithAtMostTwoDistinctChars = Math.max(maxSubstringWithAtMostTwoDistinctChars, rightPointer - leftPointer);
    }
    return maxSubstringWithAtMostTwoDistinctChars;
};
