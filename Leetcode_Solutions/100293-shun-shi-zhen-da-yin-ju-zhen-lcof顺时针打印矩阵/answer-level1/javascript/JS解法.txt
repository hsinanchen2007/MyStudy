
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if(matrix == null || !matrix.length || !matrix[0].length){
        return []
    }
    let left = 0,
        right = matrix[0].length-1,
        top = 0,
        bottom = matrix.length-1;
    let result = [];
    while(true){
        for(let col=left;col<=right;col++){
            result.push(matrix[top][col])
        }
        top++;
        if(top>bottom){
            break;
        }
        for(let row=top;row<=bottom;row++){
            result.push(matrix[row][right])
        }
        right--;
        if(right<left){
            break;
        }
        for(let col=right;col>=left;col--){
            result.push(matrix[bottom][col])
        }
        bottom--;
        if(bottom<top){
            break;
        }
        for(let row=bottom;row>=top;row--){
            result.push(matrix[row][left])
        }
        left++;
        if(left>right){
            break;
        }
    }
    return result
};
```