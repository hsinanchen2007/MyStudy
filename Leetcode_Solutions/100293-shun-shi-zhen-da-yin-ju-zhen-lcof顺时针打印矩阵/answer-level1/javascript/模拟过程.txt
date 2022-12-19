### 解题思路
通用模版

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if(matrix.length==0){
        return []
    }
    let up = 0;
    let down = matrix.length-1;
    let left = 0;
    let right = matrix[0].length-1;

    const res = [];

    while (left<=right&&up<=down){
        //从左往右
        for(let i=left;i<=right;i++){
            res.push(matrix[up][i])
        }
        up=up+1;

        if(up>down){
            break
        }
        //从上往下
        for(let j=up;j<=down;j++){
            res.push(matrix[j][right])
        }
        right = right-1;

        if(left>right){
            break
        }
        //从左到右
        for(let z = right;z>=left;z--){
            res.push(matrix[down][z])
        }
        down = down - 1;
        //从下到上
        for(let d = down;d>=up;d--){
            res.push(matrix[d][left])
        }

        left = left +1;
    } 

    return res


};
```