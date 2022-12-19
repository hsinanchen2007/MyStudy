1. 本题确实刚开始没看懂题目，后来看了解答才明白解题思路。
2. 选取动态规划递推公式dp[i][m],代表从第i个物品开始先手，且M值当前为m，所能取得的最大值。
3. 本题目的关键在于假设亚历克斯和李都发挥出最佳水平，即二者都会发挥出最佳水平，我们假设
亚历克斯先手后，李继续以最优水平发挥后所能获得的最大值应该尽可能的小，即score（alex） = sum - score（lee）；我们应尽可能的让score（lee）最小，我们遍历 1 <= X <= 2M,
score（alex） = sum - min(dp[i+X][max(M,X)]) ,其中  1 <= X <= 2Mcurr;
4. 最终求出dp[0][1]的值，即为返回结果.
```
class Solution {
public:
    int helper(vector<int>& piles,int i,int M,int sum,vector<vector<int>> &dp){
        if(i >= piles.size()){
            return 0;
        }
        
        if(dp[i][M] == 0){
            int take = 0;
            int maxRes = 0;
            for(int j = 1; j <= M*2 && i + j <= piles.size(); ++j){
                take += piles[i+j-1];
                maxRes = max(maxRes,sum - helper(piles,i+j,max(j,M),sum - take,dp));
            }
            dp[i][M] = maxRes;
        }
        
        return dp[i][M];
    }
    
    int stoneGameII(vector<int>& piles){
        int n = piles.size();
        int sum = 0;
        vector<vector<int>> dp(n,vector<int>(2*n+1,0));
        for(auto p : piles){
            sum += p;
        }
        
        return helper(piles,0,1,sum,dp);
    }
};
```