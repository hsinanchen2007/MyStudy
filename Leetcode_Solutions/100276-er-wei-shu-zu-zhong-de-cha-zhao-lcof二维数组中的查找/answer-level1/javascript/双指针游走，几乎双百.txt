
![image.png](https://pic.leetcode-cn.com/d5cecec40b890f83f5e07e4a4fe2e37575bd97ec6ea58d032c6cbd53e4336155-image.png)


```
var findNumberIn2DArray = function(matrix, target) {
    let y = matrix.length
    let x = 0
    const xLen = matrix[0] && matrix[0].length
    if (!y || !xLen) return false
    while(x <= xLen - 1 && y - 1 >= 0) {
        if (target === matrix[y - 1][x]) return true
        target > matrix[y - 1][x] ? x++ : y--
    }
    return false
};
```