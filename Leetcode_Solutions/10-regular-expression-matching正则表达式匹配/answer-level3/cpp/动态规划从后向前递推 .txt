    
c++
```
bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;
        for(int i=m;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                bool first = i<m &&  (s[i]==p[j] || p[j]=='.');
                if(j+1<n&&p[j+1]=='*')
                {
                    dp[i][j] = dp[i][j+2] || (first && dp[i+1][j]);
                }else
                {
                    dp[i][j] = first && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
```
c#
```
    public bool IsMatch(string s, string p) {
        bool[,] dp = new bool[s.Length + 1, p.Length + 1];
        dp[s.Length, p.Length] = true;
        for(int i=s.Length;i>=0;i--)
        {
            for(int j=p.Length-1;j>=0;j--)
            {
                bool firstmatch = i < s.Length && (p[j] == s[i] || p[j] == '.');
                if(j+1<p.Length&&p[j+1]=='*')
                {
                    dp[i, j] = dp[i, j + 2] || firstmatch && dp[i + 1,j];
                }else
                {
                    dp[i, j] = firstmatch && dp[i + 1, j + 1];
                }
            }
        }
        return dp[0, 0];
    }
```



