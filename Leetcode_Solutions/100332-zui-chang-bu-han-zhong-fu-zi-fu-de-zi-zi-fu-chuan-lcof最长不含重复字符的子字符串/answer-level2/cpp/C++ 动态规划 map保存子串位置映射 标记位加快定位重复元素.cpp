### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(!len) return 0;
        map<char, int> mp;  //字符-s位置映射
        vector<int> dp(len);
        mp[s[0]] = 0;
        dp[0] = 1;
        int maxLen = 1, start = 0;
        for(int i=1; i<len; i++){
            mp[s[i]] = i;   //更新map
            if(mp.size() != dp[i-1]+1){
                if(s[i] == s[i-1]){
                    dp[i] = 1;
                    mp.clear();
                    mp[s[i]] = i;
                    start = i;
                }
                else{
                    int lastSame = find(s.begin()+start, s.begin()+i, s[i]) - s.begin();
                    dp[i] = i - lastSame;   //之前有重复
                    for(map<char, int>::iterator it=mp.begin(); it!=mp.end(); ){
                        if(it->second <= lastSame) it = mp.erase(it);
                        else ++it;
                    }
                    start = lastSame + 1;
                }
            }
            else{
                dp[i] = dp[i-1] + 1;   //更新dp数组
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
```