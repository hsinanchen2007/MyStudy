### 解题思路
重点是转换参考系，用字典里的每一个串去试当前能否匹配到，而不是用当前的串去匹配字典。

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        s = "0" + s;
        int m = wordDict.size();
        bool dp[1000] = {false};
        dp[0] = true;
    for(int i = 1 ; i <= n ; ++i)
    {
        //cout<<temp<<endl;
        for(int j = 0 ; j < m ; ++j)
        {
            int len = wordDict[j].length();
            if(i - len < 0)
                continue;
            string temp = s.substr(i - len + 1, len);
          // cout<<temp<<endl;
            if(wordDict[j] == temp && dp[i - len] == true)
            {
               // cout<<temp<<endl;
                dp[i] = true;
            }
        }
    }
         return dp[n];
    }
};
```