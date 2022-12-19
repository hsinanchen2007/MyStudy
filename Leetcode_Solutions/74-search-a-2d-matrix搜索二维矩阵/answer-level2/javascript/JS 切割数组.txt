### 解题思路
因为 横向递增，所以我们从matrix[0][ylen-1]开始
如果 target > matrix[0][ylen-1]，说明这一行中一定没有答案，i++
如果 target < matrix[0][ylen-1]，说明答案只可能在这一行，并且在右边，j--

迭代，直到越界。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let xlen = matrix.length;
    if(xlen <= 0){
        return false;
    }
    let ylen = matrix[0].length;
    if(target > matrix[xlen-1][ylen-1] || target < matrix[0][0]){
        return false;
    }
    let i = 0, j = ylen-1;
    while( i < xlen && j >= 0){
        if(matrix[i][j] == target){
            return true;
        }else if(matrix[i][j] < target){
            i++;
        }else if(matrix[i][j] > target){
            j--;
        }
    }
    return false;  
};
```