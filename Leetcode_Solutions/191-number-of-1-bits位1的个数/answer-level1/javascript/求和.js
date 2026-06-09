### 解题思路
只求值为1的数量，那就求和咯，和是多少，就有多少个1

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    return n.toString(2).split('').reduce((x,y)=>x*1+y*1)
};
```