### 解题思路
筛选出偶数的 + 筛选出奇数的

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    return A.filter(t=>t%2===0).concat(A.filter(t=>t%2===1))
};
```