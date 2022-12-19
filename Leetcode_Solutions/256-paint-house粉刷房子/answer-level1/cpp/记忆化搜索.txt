### 解题思路
记忆化搜索

### 代码

```cpp
const int maxn = 1000+5;
class Solution {
private:
    int dp[maxn][maxn];
public:
    Solution()
    {
        memset(dp,0,sizeof(dp));
    }
    //记忆化搜索   普通回溯搜索剪枝会超时
    //递归：返回值  调用单元    终止条件
    //自顶向下分析问题，自顶向下解决问题
    int dfs(vector<vector<int>>& costs,int rol,int col)
    {
        if(rol==0) {
            return dp[rol][col] = costs[rol][col];
        }
        if(dp[rol][col]!=0) return dp[rol][col];
        if(col==0) {
            return dp[rol][col] = min(dfs(costs,rol-1,1),dfs(costs,rol-1,2)) + costs[rol][col];
        }
        if(col==1) {
            return dp[rol][col] = min(dfs(costs,rol-1,0),dfs(costs,rol-1,2)) + costs[rol][col];
        }
        if(col==2) {
            return dp[rol][col] = min(dfs(costs,rol-1,0),dfs(costs,rol-1,1)) + costs[rol][col];
        }
        return -1;
    }
    int minCost(vector<vector<int>>& costs) {
        int r = costs.size();
        if(r==0) return 0;
        if(r==1) return min(costs[0][0],min(costs[0][1],costs[0][2]));
        return min(dfs(costs,r-1,0),min(dfs(costs,r-1,1),dfs(costs,r-1,2)));
    }
};
```