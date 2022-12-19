### 代码

```javascript
var merge = function(A, m, B, n) {
    A.splice(m, n, ...B)
    return A.sort((a, b) => a - b)
};
```
时间复杂度：O(nlogn)
空间复杂度：O(1)