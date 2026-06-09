### 解题思路
如题

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let subStr = [];
    let maxLen = 0;
    for(let char of s) {
        let subIdx = subStr.indexOf(char);
        if (subIdx > -1) {
            subStr = subStr.splice(subIdx + 1);
        }
        subStr.push(char);
        maxLen = Math.max(maxLen, subStr.length);
    }
    return maxLen;
};
```