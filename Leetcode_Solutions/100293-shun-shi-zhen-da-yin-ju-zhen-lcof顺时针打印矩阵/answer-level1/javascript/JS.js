### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (matrix.length == 0){
        return [];
    }
   let i=0, j=0, spiralM = [], beginRow = 0, beginColum = 0, endRow = matrix.length, 
   endColum = matrix[0].length;
    while(i<matrix.length/2){
       while(j<endColum){
           spiralM.push(matrix[i][j]);
           j += 1;
       }
       j -= 1;
       i += 1;
       if(i==endRow){
           break;
       }
      while(i<endRow){
           spiralM.push(matrix[i][j]);
           i += 1;
       }
       i -= 1;
       j -= 1;
       if (j<beginColum){
           break;
       }
      while (j>=beginColum){
           spiralM.push(matrix[i][j]);
           j -= 1;
       }
       j += 1;
       i -= 1;
       if (i<=beginRow){
           break;
       }
       while(i>beginRow){
           spiralM.push(matrix[i][j]);
           i -= 1;
       }
       beginRow += 1;
       beginColum += 1;
       endRow -= 1;
       endColum -= 1; 
       i += 1;
       j += 1;
       if (i == beginRow && j == endColum){
           break;
       }
    }
    return spiralM;
       
                             
};
```