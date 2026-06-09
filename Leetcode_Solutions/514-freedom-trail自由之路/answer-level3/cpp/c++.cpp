1. 记录所有字符出现的位置.
2. 主要比较本次字符与上次字符出现的位置.
```
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.size();
        int n = ring.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));                
        vector<vector<int>> idx(26,vector<int>());
        
        /*initial*/
        for(int i = 0;i < n; ++i){
            idx[ring[i]-'a'].push_back(i);
        }
        
        /*tranverse*/
        for(int i = 0;i < m; ++i){
            int c1 = key[i]-'a';
            for(int j = 0;j < idx[c1].size(); ++j){
                int curr = idx[c1][j];
                int prev = 0;
                
                if(i <= 0){
                    dp[i][curr] = min(dp[i][curr],min(abs(curr-prev),n-abs(curr-prev))+1);
                }else{
                    int c2 = key[i-1] - 'a';
                    for(int k = 0;k < idx[c2].size(); ++k){
                        prev = idx[c2][k];
                        if(dp[i-1][prev] != INT_MAX){
                           dp[i][curr] = min(dp[i][curr],dp[i-1][prev] + min(abs(curr-prev),n-abs(curr-prev))+1); 
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i < n; ++i){
            ans = min(ans,dp[m-1][i]);
        }
        
        return ans;
    }
};
```