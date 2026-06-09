### 解题思路
![image.png](https://pic.leetcode-cn.com/802aeba8a3081bf23567bbc6372814a89846302f648dcdedf010c129780f8562-image.png)


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    if (!matrix.length) return false
    let n = matrix.length, m = matrix[0].length;
    for (let i = 0; i < n; i++) {
        if (matrix[i][0] > target) {
            return false;
        }else if (matrix[i][m-1] < target){
            continue;
        }
        for (let j = 0; j < m; j++) {
            if (matrix[i][j] > target) {
                break;
            } else if (matrix[i][j] === target) {
                return true;
            }
        }
    }
    return false;
};
```