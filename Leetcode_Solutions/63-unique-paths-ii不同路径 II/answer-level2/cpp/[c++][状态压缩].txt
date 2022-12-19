
### 代码

```cpp
using namespace std;

class Solution{
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& g){
            if(!g.size() || !g[0].size()) return 0;
            vector<long> dp(g[0].size(), 0);
            int i, d;
            dp[0] = !g[0][0];
            for(i = 1;i<g[0].size();i++) dp[i] = (!g[0][i])*dp[i-1];
            for(d = 0;d < g.size();d++) if(g[d][0]) break;
            for(i=1;i<g.size();i++){
                dp[0] = (i < d);
                for(int j=1;j<g[0].size();j++){
                    dp[j] += dp[j-1];
                    dp[j] *= !g[i][j];
                }
            }
            return dp[g[0].size()-1];
        }
};

```