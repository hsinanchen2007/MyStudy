### 解题思路
记忆化搜索

### 代码

```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        if(d>n) return -1;
        int temp=INT_MIN;
        int ans=0x3f3f3f3f;
        for(int i=0;i<n;i++){
            temp=max(temp,jobDifficulty[i]);
            int current=dfs(i,d-1,jobDifficulty,dp);
            ans=min(ans,current+temp);
        }
        return ans;
    }

    int dfs(int i,int d,vector<int>& jobDifficulty,vector<vector<int>>& dp){
        if(dp[i][d]!=-1) return dp[i][d];
        int n=jobDifficulty.size();
        if(i==n-1&&d!=0) return 0x3f3f3f3f;
        if(i!=n-1&&d==0) return 0x3f3f3f3f;
        if(d==0&&i==n-1) {
            return 0;
        }
        int ans=0x3f3f3f3f;
        for(int j=1;i+j<n;j++){
            int maxVal=INT_MIN;
            for(int s=i+1;s<=i+j;s++){
                maxVal=max(maxVal,jobDifficulty[s]);
            }
            int current=dfs(i+j,d-1,jobDifficulty,dp);
            current+=maxVal;
            ans=min(ans,current);
        }
        dp[i][d]=ans;
        return ans;
    }
};
```