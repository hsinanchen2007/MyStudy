### 解题思路
- 遍历全部元素
- 判断每个元素与其左上角元素是否相同

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
    let R = matrix.length
    let C = matrix[0].length
    if(R === 1 || C === 1) return true
    for(let i = 1; i < R; i++){
        for(let j = 1; j < C; j++)
            if(matrix[i][j] !== matrix[i-1][j-1]){
                return false
            }else{
            }
    }
    return true
};
```