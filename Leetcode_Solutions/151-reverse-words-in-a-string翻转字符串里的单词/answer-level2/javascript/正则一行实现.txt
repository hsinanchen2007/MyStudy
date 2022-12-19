### 解题思路
此处撰写解题思路
将句子按照空格分割为数组然后反转再连接
### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(" ");
};
```