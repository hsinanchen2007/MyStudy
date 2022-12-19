思路：

如果数组长度为0，直接返回

这个数字如果存在的话，肯定要大于等于 matrix[i][0]，并且小于等于 matrix[i][m-1]，满足这个条件，看看这个数组中是否包含target，如果包含直接返回true。如果遍历完还没找到，返回false.

```js
var findNumberIn2DArray = function(matrix, target) {
    let n = matrix.length;
    if(n === 0) return target;
    let m = matrix[0].length;
    for(let i = 0; i < n; i++) {
        if(target >= matrix[i][0] && target <= matrix[i][m-1]) {
            if(matrix[i].indexOf(target) !== -1) {
                return true;
            } 
        }
    }
    return false;
};
```

执行用时 :56 ms, 在所有 JavaScript 提交中击败了99.09%的用户
内存消耗 :36.5 MB, 在所有 JavaScript 提交中击败了100.00%的用户