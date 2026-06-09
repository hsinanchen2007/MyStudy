### 解题思路
分析一下，这个是n*n的矩阵，最后一行变成第一列，倒数第二行变成变成第二列，以此类推，新matrix[i][j] = 老matrix[n-1-i]][j]
### 代码

```java
class Solution {
    public void rotate(int[][] matrix ) {
        int l = matrix .length-1;
        int[][] rs = new int[l+1][l+1];

         for(int i=0;i<=l;i++){
            for(int j=0;j<=l;j++){
                rs[i][j] = matrix[i][j]; 
            }
        }
        for(int i=0;i<=l;i++){
            for(int j=0;j<=l;j++){
                matrix[j][i] = rs[l-i][j]; 
            }
        }
    }
}
```