```
class Solution {
public:
    int longestPalindromeSubseq(string s) {            
        int n = s.size();
        if (n<2) return n;

        int dp[n][n]={0}; //编译器报错？

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n - i; j++)
            {
                int col = j;
                int row = j + i;
    
                if (i == 0) { dp[col][row] = 1; continue; }

                if (s[col] == s[row]) dp[col][row] = dp[col + 1][row - 1] + 2;
                else dp[col][row] = max(dp[col + 1][row], dp[col][row - 1]);
            }
        }
        return dp[0][n-1];
    }
};

```

/*
col     0   1   2   3   4   5
row  0  1      
     1      1   
     2          1     
     3              1  
     4                  1  
     5                      1


*/