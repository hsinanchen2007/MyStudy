**执行用时 :56 ms, 在所有 JavaScript 提交中击败了96.22%的用户
内存消耗 :34.2 MB, 在所有 JavaScript 提交中击败了97.37%的用户**

```
var searchMatrix = function(matrix, target) {
    for(let i = matrix.length-1;i >= 0;i--){
        if(matrix[i][0] <= target){
            return matrix[i].indexOf(target) !== -1
        }
    }
    return false
};
```