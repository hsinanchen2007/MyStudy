因为只能做加一的操作，那么首先将数组排序。

对于重复的数字，可以使其加一，直到不包含重复的数字为止。
但是我们可以从头开始遍历数组，只要确保数组中的每一个元素比前一个元素至少大 1 即可。

想象成爬阶梯一样，前一阶至少比后一阶高度大 1。

所以我们只需要从头开始遍历，判断每一个数字是否大于等于当前台阶应有的高度。

若小于，加上操作数和更新阶梯高度。
若大于，只需更新高度即可。


```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    A = A.sort((a, b) => a - b);
    let move = 0;
    for (let i = 1, len = A.length; i < len; i++) {
        if (A[i] <= A[i - 1]) {
            const val = A[i];
            A[i] = A[i - 1] + 1;
            move += A[i] - val;
        }
    }
    return move;
};
```