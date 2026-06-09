### 解题思路
起点分别是第一行的所有元素和第一列的所有元素,
遍历以他们为起点时是否每一个斜下方元素都与之相等，如果不相等就返回false，


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
    let row=matrix.length;
    let col=matrix[0].length;
    for(let j=0;j<col;j++){
        let r=0,c=j;
        while(r<row-1 && c<col-1 ){
            if(matrix[r][c]!=matrix[r+1][c+1]){
                return false;
            }
            r++;
            c++;
        }
    }
    for(let i=0;i<row;i++){
        let c=0,r=i;
        while(r<row-1 && c<col-1 ){
            if(matrix[r][c]!=matrix[r+1][c+1]){
                return false;
            }
            r++;
            c++;
        }
    }
    return true;
};
```