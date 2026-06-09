### 解题思路
这题先排下序就很好做了，升序排序。

然后遍历数组，如果当前遍历的数小于或等于前一个数，说明要move

计算当前数和前一个数的差值再加1，就实现了当前数比前一个数多1。

> 我开始想到的是当找到小于或等于的情况下while循环当前数+1直到大于，这样执行用时2236ms。。。所以就思考既然是有序的那么直接加差值不就好了吗，，

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
   let move = 0
  A = A.sort((a,b) => a - b)
  for (let i = 1; i < A.length; i++) {
    if (A[i] <= A[i-1]) {
      let n = A[i-1]+1 - A[i]
      A[i] += n
      move += n
    }
  }
  return move
};
```