class Solution {
public:
    bool divisorGame(int N) {
        if (N==1) return false;
        
        bool dp[N+1] = {};
        dp[1] = false;
        for (int i = 2; i <= N; ++i)
        {
            for (int j = 1; j*j<=i; ++j)
            {
                if (i%j==0)
                {
                    if (dp[i-j]==false)
                    {
                        dp[i] = true;
                        break;
                    }   
                }
            }
        }
        
        return dp[N];
    }
};