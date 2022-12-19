```
class Solution {
public:
    int MAX_MOD = 1e9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        // dp[i][j][k] means i th generates a num j at repeat time k has dp[i][j][k] cases
        // i -> [1, n] j -> [1, 6] k -> [1, 15]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16, 0)));
        int i, j, k;
        for(j = 0; j < 6; j ++){
            dp[0][j][1] = 1;
        }
        for(i = 1; i < n; i ++){
            for(j = 0; j < 6; j ++){
                for(k = 1; k <= rollMax[j]; k ++){
                    if(k == 1){
                        for(int pre_j = 0; pre_j < 6; pre_j ++){
                            for(int pre_k = 1; pre_k <= rollMax[pre_j]; pre_k ++){
                                if(pre_j != j){
                                    dp[i][j][k] += dp[i - 1][pre_j][pre_k];
                                    dp[i][j][k] %= MAX_MOD;
                                }
                            }
                        }
                    }else{
                        dp[i][j][k] += dp[i - 1][j][k - 1];
                        dp[i][j][k] %= MAX_MOD;
                    }
                }
            }
        }
        int result = 0;
        for(j = 0; j < 6; j ++){
            for(k = 1; k <= 15; k ++){
                result += dp[n - 1][j][k];
                result %= MAX_MOD;
            }a
        }
        return result;
    }
};
```
