
/**
 * @param {string} input
 * @return {number}
 */
var lengthOfLongestSubstringTwoDistinct = function (input) {
    if (input.length < 3) {
        return input.length;
    }

    const ascii_z = 'z'.codePointAt(0);
    const ascii_A = 'A'.codePointAt(0);
    let ascii_codePointDifference = ascii_z - ascii_A;
    const frequency = new Array(ascii_codePointDifference + 1).fill(0);

    let maxSubstringWithAtMostTwoDistinctChars = 0;
    let numberOdDistinctChars = 0;
    let leftPointer = 0;
    let rightPointer = 0;

    while (rightPointer < input.length) {
        let currentCharCodePoint = input.codePointAt(rightPointer);
        numberOdDistinctChars += (frequency[currentCharCodePoint - ascii_A] === 0) ? 1 : 0;
        ++frequency[currentCharCodePoint - ascii_A];
        ++rightPointer;

        if (numberOdDistinctChars < 3) {
            maxSubstringWithAtMostTwoDistinctChars = Math.max(maxSubstringWithAtMostTwoDistinctChars, rightPointer - leftPointer);
            continue;
        }

        //boundary checking is not necessary: at this point there are 3 distinct chars.
        while (--frequency[input.codePointAt(leftPointer) - ascii_A] > 0) {
            ++leftPointer;
        }
        ++leftPointer;
        --numberOdDistinctChars;

    }
    return maxSubstringWithAtMostTwoDistinctChars;
};
