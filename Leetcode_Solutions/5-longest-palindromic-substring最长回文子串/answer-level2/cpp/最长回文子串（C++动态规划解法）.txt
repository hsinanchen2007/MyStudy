令dp[i][j]表示s[i]至s[j]所表示的子串是否为回文串，是则为1，否则为0。  
由此可以写出状态转移方程：当s[i]==s[j]时，dp[i][j] = dp[i+1][j-1]，当s[i]!=s[j]时，dp[i][j] = 0。  
此处的代码是先单独找出长度为1和2的回文串（设置dp），再找出长度为3及以上的回文串。
```
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size == 0) return "";
        //dp[i][j]表示s[i]至s[j]所表示的子串是否为回文串
        int dp[1001][1001] = {0};
        int start = 0, end = 0;
        for(int i = 0; i < size; i++)
        {
            dp[i][i] = 1;
            if(i < size - 1)
            {
                if(s[i] == s[i+1])
                {
                    dp[i][i+1] = 1;
                    start = i;
                    end = i+1;
                }
            }
        }
        for(int l = 3; l <= size; l++)
        {
            for(int i = 0; i + l - 1 < size; i++)
            {
                int j = i + l -1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                    start = i;
                    end = j;
                }
            }
        }
        string str = s.substr(start, end-start+1);
        return str;
    }
};
```
