### 解题思路
记dp[i]为长度为i(下标0~i-1)的子串是否能单词拆分，
那么对于dp[j]，若dp[j]能拆分且长度为i-j(下标j~i-1)的子串在候选项中，那么dp[i]就能拆分；
递推公式:
if(dp[j] && wordDict.has(s.substr(j,i-j))) dp[i] = true;
### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        unordered_set<string> _set(wordDict.begin(),wordDict.end());
        for(int i = 1;i <= s.size();++i){
            for(int j = 0;j < i;++j){
                if(dp[j] && _set.count(s.substr(j,i-j)))
                    dp[i] = 1;
            }
        }
        return dp.back();
    }
};
```