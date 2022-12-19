### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let arr =[]

    const num = matrix[0].length
    for (let i=0;i<num;i++){ 
        matrix.push(getArr(matrix,i,num))
    }

    matrix.splice(0,num)
};

function getArr(arr,index,num){
    let one = [];
    for (let i=0;i<num;i++){
        one.push(arr[i][index])
    }
    one.reverse()
    return one
}
```