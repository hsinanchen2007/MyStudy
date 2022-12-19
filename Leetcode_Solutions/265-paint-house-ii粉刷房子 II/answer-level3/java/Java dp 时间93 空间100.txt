从[256](https://leetcode-cn.com/problems/paint-house/) 过来的，基本上是一模一样的题目了。就是加了一个要求，在O(nk)的时间内完成。

由于256 中采用了二维dp，且递推关系为 dp[i][0] = Math.min(dp[i-1][1],dp[i-1][2])+costs[i][0];dp[i][1] = Math.min(dp[i-1][0],dp[i-1][2])+costs[i][1];dp[i][2] = Math.min(dp[i-1][1],dp[i-1][0])+costs[i][2]; 

这里如果再采用相同的思路，dp[i][0..k-1]的每一格都要先比较上一层的k-1格之后才能得出结果，此时的复杂度为 k*k-1*n 不满足要求。

再仔细思索，假设上一层取最小时，花费为dp[i-1][j], 此时，当前层，除了dp[i][j]不能用dp[i-1][j]+cost[i][j]之外，其他均可以使用，而dp[i][j]变为dp[i-1]中的次小值+cost[i][j]。

此时如果对dp[i-1]中元素进行一次遍历，找到最小值和次小值，所需时间为k，再对dp[i]赋值，所需时间k，共n层，时间为O(2nk)
```
int len = costs.length;
        if(len==0) return 0;
        int k = costs[0].length;
        int[][] dp = new int[len][k];
        for(int j=0;j<k;j++)
        {
            dp[0][j] = costs[0][j];
        }
        for(int i=1;i<len;i++)
        {
            int Min = Integer.MAX_VALUE;
            int min = Integer.MAX_VALUE;
            int Mindex = k+1;
            int mindex = k+1;
            for(int j=0;j<k;j++)
            {
                if(dp[i-1][j]<Min)
                {
                    min = Min;
                    mindex = Mindex;
                    Min = dp[i-1][j];
                    Mindex = j;

                }
                else if(Min<=dp[i-1][j]&&dp[i-1][j]<min)
                {
                    min = dp[i-1][j];
                    mindex = j;
                }
            }
            for(int j=0;j<k;j++)
            {
                if(j!=Mindex)
                {
                    dp[i][j] = Min+costs[i][j];
                }
                else
                {
                    dp[i][j] = min+costs[i][j];
                }
            }
        }
        int ans=Integer.MAX_VALUE;
        for(int j=0;j<k;j++)
        {
            if(dp[len-1][j]<ans)
            {
                ans = dp[len-1][j];
            }
        }
        return ans;
```
