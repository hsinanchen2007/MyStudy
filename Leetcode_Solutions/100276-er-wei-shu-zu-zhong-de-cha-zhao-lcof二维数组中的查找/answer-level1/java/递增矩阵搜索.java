### 解题思路
可以从矩阵的右上角开始检索，当目标值大于当前矩阵值时，则向下搜索；当当目标值小于当前矩阵值时，则向左搜索。这样可以确保搜索完所有的可能值。在此基础上添加一些初始判断（与最大值和最小值比较）可以提高效率。

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length==0||matrix[0].length==0){
            return false;
        }
        int m=matrix.length, n=matrix[0].length;
        int i=0,j=n-1;
        if(matrix[0][0]>target||matrix[m-1][n-1]<target){
            return false;
        }
        while(i<m&&j>=0){
            if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j]<target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
}
```