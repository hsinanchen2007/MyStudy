### 解题思路
直接莽
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let a = []
    for(let item of matrix){
        a = [...a,...item]
    }
    if(a.findIndex(item=>item==target)>-1){
        return true
    }
    return false
};
```