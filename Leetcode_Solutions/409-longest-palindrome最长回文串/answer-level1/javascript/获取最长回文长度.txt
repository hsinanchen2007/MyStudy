### 解题思路
此处撰写解题思路
1、判断字符串中每个子串出现的次数
2、考虑回文字符串的定义，如果是偶数，是完全没问题的，如果是奇数的话，需要减1才可以形成对称
3、判断原始字符串中是否有子串出现过奇数次，如果出现过，则 + 1，如果没有，则直接返回结果
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    const obj = {}
    for (let i = 0; i < s.length; i += 1) {
        if (!obj[s[i]]) {
            obj[s[i]] = 0
        }
        obj[s[i]] += 1
    }
    let num = 0
    let hasOdd = false
    Object.keys(obj).forEach((item) => {
        if (obj[item] % 2 === 0) {
            num += obj[item]
        } else if (obj[item] % 2 != 0 ) {
            hasOdd = true
            if (obj[item] > 1) {
                num += obj[item] - 1
            }
        }
    })
    if (hasOdd) {
        return num + 1
    }
    return num
};
```