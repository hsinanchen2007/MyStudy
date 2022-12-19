### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(!wordBreak2(s, wordDict)) return vector<string>();
        vector<vector<string>> dp(s.size() + 10);
        set<string> hash;
        for(auto t : wordDict) hash.insert(t);
        dp[0].push_back("");
        for(int i = 1;i <= s.size();++i){
            for(int j = 0;j < i;++j){
                if(dp[j].size() > 0 && hash.count(s.substr(j, i-j))){
                    for(auto t : dp[j]){
                        dp[i].push_back(t + (t == "" ? "" : " ") + s.substr(j, i-j));
                    }
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak2(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+10, false);//在 i 和 i - 1 之间那个位置切开
        set<string> hash;
        for(auto t : wordDict) hash.insert(t);
        dp[0] = true;
        for(int i = 1;i <= s.size();++i){
            for(int j = 0;j < i;++j){
                if(dp[j] && hash.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```