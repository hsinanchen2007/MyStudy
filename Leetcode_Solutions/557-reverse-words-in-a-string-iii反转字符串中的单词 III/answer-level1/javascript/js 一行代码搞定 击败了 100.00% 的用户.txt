
![](https://pic.leetcode-cn.com/8e0af586e09b9b01044208559c523e8442e9bef25406462685dcbd612c7a5e56.png)
### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split('').reverse().join('').split(/\s+/).reverse().join(' ')
};
```