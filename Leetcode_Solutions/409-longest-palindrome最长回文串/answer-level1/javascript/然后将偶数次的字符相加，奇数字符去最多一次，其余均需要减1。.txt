### 解题思路
解体思路：由于回文必须成对出现，所以基于该字符串判断所有字母，并可出现最多一次奇数，
然后将偶数次的字符相加，奇数字符去最多一次，其余均需要减1。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    const characterMapping = {};
    for (const c of s) {
        if (!characterMapping[c]) {
            characterMapping[c] = 0;
        }
        characterMapping[c] += 1;
    }
    let total = 0;
    let added = false;
    for (const c in characterMapping) {
        if (characterMapping[c] % 2 === 0) {
            total += characterMapping[c];
        } else {
            if (!added) {
                total += characterMapping[c];
                added = true;
            } else {
                total += characterMapping[c] - 1;
            }
        }
    }
    return total;
};
```