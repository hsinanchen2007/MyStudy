### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
// 两个字符串寻找最初公共前缀
function findCommon(a, b) {
    const length = Math.min(a.length, b.length);
    let common = '';
    for (let i = 0; i < length; i ++) {
        if (a[i] !== b[i]) {
            break;
        }
        common += a[i];
    }
    return common;
}
// 两两轮询作为结果与下一个继续轮询递进，即用第1个和第2个的最长公共前缀，来和第三个匹配寻找最长公共前缀
var longestCommonPrefix = function(strs) {
    const length = strs.length;
    let common = strs[0] || '';
    for (let i = 1; i < length; i ++) {
        common = findCommon(common, strs[i]);
        if (common === '') {
            break;
        }
    }
    return common;
};
```