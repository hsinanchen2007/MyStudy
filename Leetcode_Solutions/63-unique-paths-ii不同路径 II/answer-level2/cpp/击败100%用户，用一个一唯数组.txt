```       
int uniquePath_2(vector<<vector<int>>& obs){
            if(obs[0][0]){
                return 0;
            }
            int sizeH = obs.size();
            int sizeL = obs[0].size();
            vector<int> dp(sizeL,1);
            dp[0]     = 1;
            for(int i=0; i<sizeH; ++i){
                for(int j=0; j<sizeL; ++j){
                    if(obs[i][j]){
                        dp[j] = 0;
                    }else if(j>0){
                        dp[j] = dp[j] + dp[j-1];
                    }
                }
            }
            return dp[sizeL-1];
}

```
