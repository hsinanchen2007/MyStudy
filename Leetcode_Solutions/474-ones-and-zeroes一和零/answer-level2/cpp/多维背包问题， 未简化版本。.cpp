此题为01背包过程，等价于取不取字符串数组中的字符串，若取，val价值+1，占用容量为0的个数与1 的个数。总容量
m为0可占用的容量，n为1可占用的容量。问题等效为，将问题分解为子问题，最优选取取或者不取，得到最后的价值最优策略，由于有两种容量（0 ， 1），故F（i ， v） 扩展为 F（i ， cap_0， cap_i）。 

```
 int findMaxForm(vector<string>& strs, int m, int n ) {
        vector<vector<int>> nums (strs.size() , vector<int>(2 , 0));
        for(int i = 0 ; i < strs.size() ; i++)
        {
            for(auto ch : strs[i])
            {
                if(ch == '0') (nums[i][0])++;
                else (nums[i][1])++;
            }

        }
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>
                                      (m + 1 , vector<int>(n + 1 , 0)));

        for(int i = 1 ;  i < strs.size() + 1; i ++ )
          for(int cap_0 = 0 ; cap_0 < m + 1 ; cap_0++ )
            for(int cap_1 = 0 ; cap_1 < n + 1 ; cap_1++)
            {
                if(cap_0 - nums[i - 1][0] >= 0 && cap_1 - nums[i - 1][1] >= 0)
                    dp[i][cap_0][cap_1] =
                            max(dp[i - 1][cap_0][cap_1] ,  dp[i - 1][cap_0 - nums[i -1][0]][cap_1                             - nums[i - 1][1]] + 1 );
                    else dp[i][cap_0][cap_1] = dp[i - 1][cap_0][cap_1];
            }
        return dp[strs.size()][m][n];
    }
```
