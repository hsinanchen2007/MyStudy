### 解题思路
用的最笨的方法。
先对数组进行升序排序，
然后循环数组，若A[i]和A[i + 1]相等，就让A[i + 1] + 1,并且count + 1;
若A[i] > A[i + 1],则A[i + 1]需要增加A[i] - A[i + 1] + 1，才能大于A[i]，同时count的增量也是
A[i] - A[i + 1] + 1

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    A.sort((a, b) => a-b);
    var count = 0;
    for(var i = 0; i < A.length; i++) {
        if(A[i] == A[i + 1]) {
            A[i + 1] += 1;
            count += 1;
        } else if (A[i] > A[i + 1]) {
            var diff = A[i] - A[i + 1]
            A[i + 1] += diff + 1;
            count += diff + 1;
        }
    }
    return count;
};
```