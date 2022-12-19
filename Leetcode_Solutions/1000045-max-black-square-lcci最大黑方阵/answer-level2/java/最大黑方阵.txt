### 解题思路
在[1139. 最大的以 1 为边界的正方形](https://leetcode-cn.com/problems/largest-1-bordered-square/)基础上增加记录正方形左上角元素位置

时间复杂度$O(n^2)$
空间复杂度$O(n^2)$

### 代码

```java
class Solution {
    public int[] findSquare(int[][] matrix) {
         int ans=0,row=0,col=0;
        int[][] dp_up=new int[matrix.length][matrix[0].length];
        int[][] dp_down=new int[matrix.length][matrix[0].length];
        int[][] dp_right=new int[matrix.length][matrix[0].length];
        int[][] dp_left=new int[matrix.length][matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(i==0) dp_up[i][j]=matrix[i][j]==0?1:0;
                else dp_up[i][j]=matrix[i][j]==0?dp_up[i-1][j]+1:0;
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(j==0) dp_left[i][j]=matrix[i][j]==0?1:0;
                else dp_left[i][j]=matrix[i][j]==0?dp_left[i][j-1]+1:0;
            }
        }
        for(int i=matrix.length-1;i>=0;i--){
            for(int j=matrix[0].length-1;j>=0;j--){
                if(i==matrix.length-1) dp_down[i][j]=matrix[i][j]==0?1:0;
                else dp_down[i][j]=matrix[i][j]==0?dp_down[i+1][j]+1:0;
            }
        }
        for(int i=matrix.length-1;i>=0;i--){
            for(int j=matrix[0].length-1;j>=0;j--){
                if(j==matrix[0].length-1) dp_right[i][j]=matrix[i][j]==0?1:0;
                else dp_right[i][j]=matrix[i][j]==0?dp_right[i][j+1]+1:0;
            }
        }

        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                int Long=1;
                while(i+Long-1<matrix.length&&j+Long-1<matrix[0].length){
                    if(matrix[i+Long-1][j+Long-1]==0&&dp_up[i+Long-1][j+Long-1]>=Long&&dp_left[i+Long-1][j+Long-1]>=Long&&dp_down[i][j]>=Long&&dp_right[i][j]>=Long) {
                        if(ans<Long) {
                            ans=Long;
                            row=i;
                            col=j;
                        }
                        else if(ans==Long){
                            if(row>i) row=i;
                            else if(row==i){
                                col=Math.min(col,j);
                            }
                        }
                        }
                    Long++;
                }
            }
        }
        return ans==0?new int[]{}:new int[]{row,col,ans};


    }
}
```