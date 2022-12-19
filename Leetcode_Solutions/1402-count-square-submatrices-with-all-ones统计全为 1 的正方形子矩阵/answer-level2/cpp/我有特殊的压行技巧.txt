### 解题思路
dp[i][j]=min(dp[i-1][j],dp[i-1][j-1],dp[i-1][j]);

### 代码

```cpp
#define MIN_THERR(a,b,c) min(c,min(a,b))
const int maxn=3e3+3;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int dp[maxn][maxn],ans=0,szn=matrix.size(),szm=matrix[0].size();
        memset(dp,0,sizeof(dp));
        for(register int i=1;i<=szn;++i)
            for(register int j=1;j<=szm;++j)
                if(matrix[i-1][j-1])
                    ans+=(dp[i][j]=MIN_THERR(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1);
        return ans;
    }
};
```