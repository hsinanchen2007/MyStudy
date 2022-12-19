### 解题思路
![1584862615(1).png](https://pic.leetcode-cn.com/03d5b2591af9b4341829a0912bca3fdebc9cda9735af06400f0d46495a4a1818-1584862615\(1\).png)
此处撰写解题思路

### 代码

```java
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int maxLen=0,col=grid[0].length,row=grid.length;
        int[][] sumX=new int[row][col],sumY=new int[col][row];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) maxLen=1;
                if(j==0){
                    sumX[i][j]=grid[i][j];
                }else {
                    sumX[i][j]=sumX[i][j-1]+grid[i][j];
                }
                if(i==0){
                    sumY[j][i]=grid[i][j];
                }else {
                    sumY[j][i]=sumY[j][i-1]+grid[i][j];
                }

            }
        }
        if(maxLen==0) return 0;
        for(int i=0;i<row-maxLen;i++){
            for(int j=0;j<col-maxLen;j++){
                if(grid[i][j]==0) continue;
                int len=maxLen;
                while (i+len<row&&j+len<col){
                    int s1=sumX[i][j+len]-sumX[i][j];
                    if(s1<len) break;
                    int s2=sumY[j][i+len]-sumY[j][i];
                    if(s2<len) break;
                    int s3=sumY[j+len][i+len]-sumY[j+len][i];
                    if(s3<len){
                        len++;
                        continue;
                    }
                    int s4=sumX[i+len][j+len]-sumX[i+len][j];
                    if(s4<len){
                        len++;
                    }else {
                        if(len>=maxLen) maxLen=len+1;
                        len++;
                    }
                }
            }
        }
        return maxLen*maxLen;
    }
}
```