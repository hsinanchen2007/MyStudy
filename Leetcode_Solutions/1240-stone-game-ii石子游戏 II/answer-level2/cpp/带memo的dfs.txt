### 解题思路
执行用时 :
4 ms, 在所有 C++ 提交中击败了92.66%的用户

### 代码

```cpp
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> memo(n,vector<int>(n/2,-1));// dp[index][M]
        // prefix sum
        vector<int> presum(n+1,0);
        for(int i=1;i<=n;i++){
            presum[i]=piles[i-1]+presum[i-1];
        }
        // dfs with memo
        return dfs(presum,memo,0,1);
    }
    int dfs(vector<int>& presum,vector<vector<int>>& memo,int ind, int M){
        // boundary
        int n=presum.size()-1;
        if(M*2>=n-ind){
            return presum.back()-presum[ind];
        }
        if(memo[ind][M]!=-1){
            return memo[ind][M];
        }
        // recursion
        int ans=-1;
        for(int i=1;i<=M*2;i++){
            ans=max(ans,presum.back()-presum[ind]-dfs(presum,memo,ind+i,max(i,M)));
        }
        memo[ind][M]=ans;
        return ans;
    }
};
```