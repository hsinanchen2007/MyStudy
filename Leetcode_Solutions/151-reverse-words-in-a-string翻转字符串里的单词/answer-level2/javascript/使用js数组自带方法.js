### 解题思路
使用js数组自带方法解题

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(" ")
};
```
### 求助：有没有思路可以优化这段代码？欢迎留言~