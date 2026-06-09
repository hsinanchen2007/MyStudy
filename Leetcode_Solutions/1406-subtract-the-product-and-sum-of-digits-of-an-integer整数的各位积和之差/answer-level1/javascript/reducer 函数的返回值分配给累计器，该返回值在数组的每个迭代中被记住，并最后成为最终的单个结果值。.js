### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let arr = n.toString().split('')
    return arr.reduce((item1, item2) => item1 * item2) - arr.reduce((item1, item2) => Number(item1) + Number(item2))
};
```