### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
    let arr = s.split('')
    arr.push(...arr.splice(0, n))
    return arr.join('')
};
```