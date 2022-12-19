### 解题思路
对于1...n的数，依次选择1,2,3，n作为根节点即可。

### 代码

```cpp
class Solution {
public:
    int dp[1007];
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        int ans=dfs(n);
        return dp[n];
    }
    int dfs(int n)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                ans+=dfs(i-1)*dfs(n-i);
            }
            dp[n]=ans;
            return ans;
        }
    }
};
```