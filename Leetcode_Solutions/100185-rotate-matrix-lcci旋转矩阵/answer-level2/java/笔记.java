### 解题思路
甜姨的思路，
输入
1,2,3
4,5,6
7,8,9

先沿对角线
1,4,7
2,5,8
3,6,9

再沿着中线
7,4,1
8,5,2
9,6,3

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
       if(matrix.length==0||matrix==null) return;
       int i,j;
       int m=matrix.length;
       int n=matrix[0].length;
       for (i=0;i<m;i++){
           for (j=0;j<i;j++){
               if(i==j) continue;
               int trans=matrix[i][j];
               matrix[i][j]=matrix[j][i];
               matrix[j][i]=trans;
           }
       }

       for (j=0;j<n/2;j++){
           for (i=0;i<m;i++){
               int trans=matrix[i][j];
               matrix[i][j]=matrix[i][n-j-1];
               matrix[i][n-j-1]=trans;
           }
       }
       


    }

}
```