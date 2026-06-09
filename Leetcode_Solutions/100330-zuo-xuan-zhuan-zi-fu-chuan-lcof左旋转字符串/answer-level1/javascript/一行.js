### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, k) {
    return s.slice(k)+s.slice(0,k)
};
```