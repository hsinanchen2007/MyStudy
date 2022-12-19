class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 状态压缩dp
        int N = s.size();
        
        vector<int> dp(N,1);
        
        // 从i开始
        for(int i = N - 1; i >= 0; --i)
        {
            // 假设N = 5, 现在到了i = 1
            // 那上一次求得的为2, dp[1] = 1, dp[2]=dp[2,2],dp[3]=dp[2,3],dp[4]=dp[2,4],dp[5]=dp[2,5]
            // dp[1,2](dp[2]) 需要 dp[2,2](dp[2]),dp[1,1](dp[1]),dp[2,1](pre=0)
            // dp[1,3](dp[3]) 需要 dp[1,2](dp[2]),dp[2,3](dp[3]),dp[2,2](上一次没有更新的dp[2])
            // dp[1,4](dp[4]) 需要 dp[1,3](dp[3]),dp[2,4](dp[4]),dp[2,3](上一次没有更新的的dp[3])
            // 所以在每次更新前都要保存之前的dp作为下一次的pre
            int pre = 0;
            for(int j = i + 1; j < N; ++j)
            {
                int tmp = dp[j];
                if(s[i] == s[j])
                {
                    dp[j] = pre + 2;
                }
                else
                {
                    dp[j] = max(dp[j],dp[j-1]);
                }
                pre = tmp;
            }
        }
        
        return dp[N-1];
    }
};