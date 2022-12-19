### 解题思路


### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let result = 0;
    for(let i = 0; i < s.length; i ++) {
        let temp = s[i];
        for(let j = i + 1; j < s.length; j ++) {
            if (!temp.includes(s[j])) {
                temp += s[j];
            } else {
                break;
            }
        }
        result = Math.max(temp.length, result);
    }
    return result;
};
```