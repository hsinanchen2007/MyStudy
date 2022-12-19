### 题解思路
- dp[i]表示s中[i,size()-1]能否被拆分

### 代码
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>m_set(wordDict.begin(), wordDict.end());
        vector<bool>dp(s.size()+1, false);//dp[i]表示s中[i,size()-1]能否被拆分
        dp[s.size()] = true;
        for(int i = s.size(); i >= 1; i--)
        {
            if(dp[i] == true)
            {
                for(int j = 0; j < i; j++)
                {
                    if(m_set.count(s.substr(j, i - j)) == 1)
                    {
                        dp[j] = true;
                        if(dp[0] == true)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
```
![image.png](https://pic.leetcode-cn.com/e10faf304c3676d2e1d1684a8fdee31f4f8d814d974945c341eb047f44b40628-image.png)
