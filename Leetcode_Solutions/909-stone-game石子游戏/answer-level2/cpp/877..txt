记忆化比区间dp好理解一点 40ms  
```
class Solution {
public:
    int dp[505][505][2];//左端是l,右端是r,现在到0/1走
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        return dfs(0,n-1,0,n,piles)>0;
    }
    int dfs(int l,int r,int x,int n,vector<int>& piles){
        if(l>r)return 0;
        if(l==r)return dp[l][r][x]=piles[l];
        if(dp[l][r][x]!=0)return dp[l][r][x];
        return dp[l][r][x]+=max(piles[l]-dfs(l+1,r,x^1,n,piles),piles[r]-dfs(l,r-1,x^1,n,piles));
    }
};
```
