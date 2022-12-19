### 解题思路

螺旋相当于每次都取最外层的所有数据，不断去绕着圈去找，直到没有数据。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    // 判空
        if(!matrix.length || !matrix[0].length) return result;
        // 定义 第一行、最后一行、最后一列、第一列
        let firstLine = matrix.shift(), lastLine = [], lastRow = [], firstRow = [];
        if(matrix.length){
            // 取最后一行数据的反转
            lastLine = matrix.pop().reverse();
        }
        if(matrix.length && matrix[0].length){
            // 正序遍历找出最后一列的所有数据
            for(let i = 0; i < matrix.length; i++ ){
                lastRow.push(matrix[i].pop());
            }
        }
        if(matrix.length && matrix[0].length){
            // 倒序遍历找出最后一列的所有数据
            for(let i = matrix.length - 1 ; i >= 0; i--){
                firstRow.push(matrix[i].shift());
            }
        }
        // 添加进数组
        result.push(...firstLine, ...lastRow, ...lastLine, ...firstRow);
        // 递归
       return getAllNum(matrix);
};
```