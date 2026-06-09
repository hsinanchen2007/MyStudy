```
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> dp(length, 0);
        for(int i=0;i<updates.size();i++) {
            dp[updates[i][0]]+=updates[i][2];
            if(updates[i][1]+1<length) {
                dp[updates[i][1]+1]-=updates[i][2];
            } 
        }
        for(int i=1;i<length;i++) {
            dp[i]+=dp[i-1];
        }
        return dp;
    }
};
```
