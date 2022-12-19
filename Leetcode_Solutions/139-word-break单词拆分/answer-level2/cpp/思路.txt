### 解题思路
本来觉得像01背包问题，但是写了写找不到关系
看了题解才会，动态规划太难想了

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      if(s.size() == 0 || wordDict.size() == 0) 
        return false;

      vector<bool>dp(s.size() + 1, false);
      dp[0] = true;

      for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j < i; j++){
          if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()){
            dp[i] = true;
            break;
          }
        }
      }

      return dp[s.size()];
    }
};
```