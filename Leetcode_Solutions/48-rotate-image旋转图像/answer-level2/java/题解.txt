### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        for(int i=0;i<=n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int tmp=matrix[i][j]; //tmp=matrix[0][1]=2
                matrix[i][j]=matrix[n-j-1][i];//matrix[0][1]=matrix[1][0]=4
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];//matrix[1][0]=matrix[2][1]=6
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];//matrix[2][1]=matrix[1][2]=2
                matrix[j][n-i-1]=tmp;
            }
        }   
    }
}

```