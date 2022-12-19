### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int m=mat.length;
        int n=mat[0].length;
        int [][] dp=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)  dp[i][j]=mat[i][j];
                else if(i==0)   dp[i][j]=dp[i][j-1]+mat[i][j];
                else if(j==0)   dp[i][j]=dp[i-1][j]+mat[i][j];
                else            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i][j];
            }
        }

        int [][] ans=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int a=Math.max(0,i-K);
                int b=Math.max(0,j-K);
                int c=Math.min(m-1,i+K);
                int d=Math.min(n-1,j+K);
                int res=dp[c][d];   //大矩形的面积
                if(a>0)
                    res-=dp[a-1][d];
                if(b>0)
                    res-=dp[c][b-1];
                if(a>0&&b>0)
                    res+=dp[a-1][b-1];
                ans[i][j]=res;
            }
        }
        return ans;
    }
}
```