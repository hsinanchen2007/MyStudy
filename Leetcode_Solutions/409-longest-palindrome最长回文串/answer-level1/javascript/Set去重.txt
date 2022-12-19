1. 思路：Set去重
2. 每个字符加入set
3. 有重复字符则length + 2，且set删除对应字符
4. 根据最终set长度输出最终length

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let length = 0
    let strSet = new Set()
    for(let char of s) {
        if(!strSet.has(char)){
            strSet.add(char)
        } else {
            length = length + 2
            strSet.delete(char)
        }
    }
    return strSet.size === 0 ? length : length + 1
};
```