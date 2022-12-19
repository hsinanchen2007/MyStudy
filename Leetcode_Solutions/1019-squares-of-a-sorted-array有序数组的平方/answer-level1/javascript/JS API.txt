### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
   return  A.map(item => item * item)
            .sort((a, b) => a - b)
};
```
时间复杂度：O(n log n)
空间复杂度：O(1)