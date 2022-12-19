### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    if (!s) return 0;
    if (s.length === 1) return 1;
    let hash = {}, res = 0;
    for (let i = 0; i < s.length; i++) {
        if (hash[s[i]]) {
            hash[s[i]] += 1;
        } else {
            hash[s[i]] = 1;
        }
    }
    let single = 0;
    for (let key in hash) {
        if (hash[key] % 2 === 0) {
            res += hash[key]
        } else if (hash[key] > 2) {
            res += hash[key] - 1;
            single = 1;
        } else {
            single = 1;
        }
    }

    return res + single;
};
```