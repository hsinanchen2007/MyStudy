### 解题思路
先找有0的行号列号，然后遍历把这些行号列号全部清零。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    let xarr = []
    let yarr = []
    let x = matrix.length   // 3
    let y = matrix[0].length   // 4

    for(let i=0;i<x;i++){     // 把有0的xy坐标存入xarr yarr
        for(let j=0;j<y;j++){
            if(matrix[i][j] === 0){
                xarr.push(i)
                yarr.push(j)
            }
        }
    }
    // console.log(xarr,yarr)

    for(let i=0;i<x;i++){     
        for(let j=0;j<y;j++){
            if(xarr.indexOf(i)!==-1 || yarr.indexOf(j)!==-1){
                matrix[i][j] = 0
            }
        }
    }

    // console.log(matrix)

};
```