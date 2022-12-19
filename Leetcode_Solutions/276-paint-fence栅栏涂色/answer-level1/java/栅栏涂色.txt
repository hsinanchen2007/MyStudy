### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numWays(int n, int k) {
        if(n==0||k==0)
            return 0;
        int [][] dp=new int[n][2];
        dp[0][0]=0;
        dp[0][1]=k;
        //dp[i][0]表示和上一个柱子颜色相同的个数
        //dp[i][1]表示和上一个柱子颜色不同的个数
        for(int i=1;i<n;i++)
        {
            dp[i][0]=dp[i-1][1];
            dp[i][1]=(dp[i-1][0]+dp[i-1][1])*(k-1);
        }
        return dp[n-1][0]+dp[n-1][1];
    }
}
```