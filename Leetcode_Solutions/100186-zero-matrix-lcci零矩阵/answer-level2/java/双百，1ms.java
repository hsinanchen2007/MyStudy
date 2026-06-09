用两个一维数组（初始化元素为1）分别记录要清零的行，然后根据matrix[i][j]*=row[i]*col[j];计算出矩阵的元素值即可

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int[] row = new int[matrix.length];
        int[] col = new int[matrix[0].length];
        int i,j,k;
        for (k = 0; k < row.length; k++) {
            row[k]=1;
        }
        for (k = 0; k < col.length; k++) {
            col[k]=1;
        }
        for(i=0;i<row.length;i++){
            for(j=0;j<col.length;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(i=0;i<row.length;i++){
            for(j=0;j<col.length;j++){
               matrix[i][j]*=row[i]*col[j];
            }
        }
    }
}
```