执行用时 :120 ms, 在所有 C++ 提交中击败了97.92%的用户
内存消耗 :31.7 MB, 在所有 C++ 提交中击败了51.43%的用户

有人说O(n^2)的C++版DP会超时，我就试了一下，然后过了（

class Solution 
{
private:  
    vector<vector<int>> dp;

public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) 
    {
        bool banned[N][N];
        memset(banned,0,sizeof(banned));

        for(auto iter = mines.begin();iter != mines.end();iter++)
        {
            banned[(*iter)[0]][(*iter)[1]] = true;
        }    

        dp = vector<vector<int>>(N,vector<int>(N));
        int cnt = 0;

        for(int i = 0;i < N;i++)
        {
            cnt = 0;

            for(int j = 0;j < N;j++)
            {
                if(banned[i][j])
                {
                    cnt = 0;
                }
                else
                {
                    dp[i][j] = ++cnt;
                }
            }

            cnt = 0;

            for(int j = N - 1;j >= 0;j--)
            {
                if(banned[i][j])
                {
                    cnt = 0;
                }
                else
                {
                    dp[i][j] = min(dp[i][j],++cnt);
                }
            }
        }

        int ans = 0;

        for(int j = 0;j < N;j++)
        {
            cnt = 0;

            for(int i = 0;i < N;i++)
            {
                if(banned[i][j])
                {
                    cnt = 0;
                }
                else
                {
                    dp[i][j] = min(dp[i][j],++cnt);
                }
            }

            cnt = 0;

            for(int i = N - 1;i >= 0;i--)
            {
                if(banned[i][j])
                {
                    cnt = 0;
                }
                else
                {
                    dp[i][j] = min(dp[i][j],++cnt);
                    ans = max(ans,dp[i][j]);
                }
            }
        }

        return ans;
    }
};