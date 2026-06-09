### 解题思路
**思考过程：**
- 如果扫描二维数组一遍，看到零就将对应一整行一整列都置为零，则会把将原本不是零的位置也置为零，如果加些标记，也会丢失一些零。所以，第一遍扫描只能将零的位置记录下来，第二遍扫描再置零。
- 所谓“将零的位置记录下来”，只需要记录哪些行哪些列需要在第二遍扫描中置零。所以需要两个数组，分别记录哪些行，哪些列。不过也可以用原来二维数组的空间，即：用第零行（列）的各个元素是否为零，来代表对应那一列（行）是否该被置为零。
- 由此带来一个问题：第零行和第零列是否要置零需要提前记录，所以设置rowZero colZero两个标记。
**总结下来，算法步骤为：**
1. 扫描第零行第零列，设置对应两个标记
2. 扫描整个二维数组，若matrix[i][j]=0,则记录matrix[i][0]=0,matrix[0][j]=0
3. 扫描第零列的从第一行开始的元素（忽略matrix[0][0]这个元素），然后整行置零。列置零方法一样
4. 检查两个标记，看第零列第零行是否需要置零

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        boolean rowZero=false;
        boolean colZero=false;
        for(int i=0;i<matrix.length;i++){
            if(matrix[i][0]==0) {
                colZero=true;
                break;
            }
        }
        for(int j=0;j<matrix[0].length;j++){
            if(matrix[0][j]==0){
                rowZero=true;
                break;
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<matrix.length;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<matrix[0].length;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<matrix[0].length;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<matrix.length;i++)
                    matrix[i][j]=0;
            }
        }
        if(rowZero){
            for(int j=0;j<matrix[0].length;j++)
                matrix[0][j]=0;
        }
        if(colZero){
            for(int i=0;i<matrix.length;i++)
                matrix[i][0]=0;
        }
    }
}
```