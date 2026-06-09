```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        if(n==1) return {"()"};

        dp[1].push_back("()");
        dp[0].push_back("");

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(string& s1:dp[j])
                {
                    for(string&s2 :dp[i-j-1])
                    {
                        dp[i].push_back("(" + s2 + ")" + s1);
                    }
                }
            }
        }
        return dp[n];
    }
};
```
