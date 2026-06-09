### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
const map = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz',
}
var letterCombinations = function(digits) {
    if (digits === '') return [];
    if (digits[0] === '1') return [];
    const result = [];

    function backtrace(i, str) {
        if (i === digits.length) {
            return result.push(str)
        }
        const s = map[digits[i]];
        for (let j = 0; j < s.length; j++) {
            backtrace(i + 1, str + s[j])
        }
    }
    backtrace(0, '')
    return result;
};





```