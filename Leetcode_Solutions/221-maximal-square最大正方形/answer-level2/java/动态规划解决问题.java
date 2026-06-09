### 解题思路
动态规划解决问题懒得优化了
### 代码

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        int Max=0,tmp=1;
        if(matrix.length==0||matrix[0].length==0)
            return Max;
        int[][] data=new int[matrix.length][matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            if(matrix[i][0]=='1') {
                data[i][0] = 1;
                Max=1;
            }
        }
        for(int i=0;i<matrix[0].length;i++){
            if(matrix[0][i]=='1') {
                data[0][i] = 1;
                Max=1;
            }
        }
        for(int i=1;i<matrix.length;i++){
            for(int j=1;j<matrix[0].length;j++){
                if(matrix[i][j]=='1'){
                    if(data[i-1][j]*data[i][j-1]*data[i-1][j-1]!=0){
                       tmp=Math.min(Math.min(data[i-1][j],data[i][j-1]),data[i-1][j-1]);
                       data[i][j]=(int)Math.pow(Math.pow(tmp,0.5)+1,2);
                    }
                    else
                        data[i][j]=1;
                    if(data[i][j]>Max)
                        Max=data[i][j];
                }
            }
        }
        return Max;
    }
}
```