### 解题思路
![image.png](https://pic.leetcode-cn.com/2aac0d3129cc03c8ca3badb23e8d43b29e71ae34de903b43e1c2a886c94c17ae-image.png)


### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(' ');
};
```