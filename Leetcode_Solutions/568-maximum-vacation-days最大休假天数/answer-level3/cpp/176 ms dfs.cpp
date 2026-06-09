### 解题思路

dfs

### 代码

```cpp
class Solution {
public:
	int n,k;
    vector<vector<int>> fl,da;
    int dp[102][102];
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if(flights.empty())return 0;
        n=flights.size();
        k=days[0].size();
        fl.swap(flights);
        da.swap(days);
        memset(dp[0],0xff,sizeof(dp));
        for(int i=0;i<n;i++)dp[i][1]=da[i][k-1];
        int ret=helper(0,k);
        for(int i=1;i<n;i++){
            if(fl[0][i])ret=max(ret,helper(i,k));
        }
        return ret;
    }
    int helper(int ind,int rem){
        if(dp[ind][rem]!=-1)return dp[ind][rem];
        int ret=helper(ind,rem-1);
        for(int i=0;i<n;i++){
            if(fl[ind][i]){
                ret=max(ret,helper(i,rem-1));
            }
        }
        return dp[ind][rem]=(ret+da[ind][k-rem]);
    }
};
```