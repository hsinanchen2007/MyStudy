### 解题思路
1、最长回文串中最多只含有一个出现奇数次的字母
2、当s中出现奇数次字母数(oddCount)不为0时，最长回文串长度为s.length - oddCount + 1
3、当oddCount = 0时，说明s本身就是一个回文串
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let arr = s.split('');
    let obj = {};
    let oddCount = 0; // 出现奇数次字母的个数
    for(const char of arr) {
        if (obj[char]) {
            obj[char] = obj[char] + 1;
        } else {
            obj[char] = 1;
        }
    }
    for(const char in obj) {
        if(obj[char] % 2 !== 0) {
            oddCount += 1;
        }
    }
    return oddCount === 0 ? s.length : s.length - oddCount + 1;
};
```