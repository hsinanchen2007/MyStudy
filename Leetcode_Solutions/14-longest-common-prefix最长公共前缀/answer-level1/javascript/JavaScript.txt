### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    // 判断是否为空
    if (!strs.length) {
        return ''
    }
    // 获取最小长度，避免越界
    let minLength = Infinity
    strs.map(item => {
        if (item.length < minLength) {
            minLength = item.length
        }
    })
    // 找到最长公共前缀
    let str = ''
    for (let i = 0; i < minLength; i++) {
        let word = strs[0][i]
        for (item of strs) {
            if (item[i] !== word) {
                return str
            }
        }
        str += word
    }
    return str
};
```