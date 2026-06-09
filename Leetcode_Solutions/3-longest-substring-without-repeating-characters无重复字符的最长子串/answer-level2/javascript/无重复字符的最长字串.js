### 解题思路
需要返回的是：最长字串的长度，设置一个默认值：maxLen = 0；
设置一个中间变量：maxStr,用来记录每个循环能得到的最长的字串

如果当前的字符在maxStr中已经出现了，那么需要重置一个maxStr

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let maxStr = '';
    let maxLen = 0;
    let sIndex = 0;
    // let series = false;
    for(let item of s) {
        sIndex = maxStr.indexOf(item);
        if( sIndex === -1) {
            maxStr += item;
        }
        else {
            maxStr = `${maxStr.slice(sIndex+1)}${item}`;
        }
        maxLen = maxStr.length > maxLen? maxStr.length: maxLen;
    }

    return maxLen;
};
```