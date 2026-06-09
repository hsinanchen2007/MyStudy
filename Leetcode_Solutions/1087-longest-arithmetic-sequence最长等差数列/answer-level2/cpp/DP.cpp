```
class Solution {
private:
    int len;
public:
    int longestArithSeqLength(vector<int>& A) {
        len = A.size();
        if(len == 0) return 0;
        vector<unordered_map<int,int> > dp(len);
        int ret = 1;
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < i; ++j){
                int gap = A[i] - A[j];
                if(dp[j][gap]) dp[i][gap] = dp[j][gap] + 1;
                else dp[i][gap] = 2;
                ret = max(dp[i][gap], ret);
            }
        }
        
        return ret;
    }
};
```