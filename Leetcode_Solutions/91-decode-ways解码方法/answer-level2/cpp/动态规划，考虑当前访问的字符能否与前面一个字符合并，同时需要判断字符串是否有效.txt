### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
        int numDecodings(string s){
        if(s.empty())
            return 0;
        if(s[0] == '0')
            return 0;
        std::vector<int> dp(s.size()+1, 1);
       // dp[1] = 1;
        for (int i = 1; i < s.size(); ++i) {
            int a = s[i] - '0';
            int b = s[i-1] - '0';
            int tmp = 10*b+a;
            if(tmp > 26){
                if( a == 0)
                    return 0;
                else
                    dp[i+1] = dp[i];
            }else if(tmp >=1){
                if(a == 0)
                    dp[i+1] = dp[i-1];
                else if(b == 0)
                    dp[i+1] = dp[i];
                else
                    dp[i+1] = dp[i] + dp[i-1];
            }else
                return 0;
        }
        return dp[s.size()];
    }

};
```