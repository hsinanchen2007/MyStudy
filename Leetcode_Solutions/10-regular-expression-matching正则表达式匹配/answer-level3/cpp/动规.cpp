### 解题思路
dp[len(s) + 1][len(p) + 1] //dp[i][j]为用前j个通配符匹配前i个字符的情况

先提前处理用0到全部通配符匹配0个字符的情况
- p[j]遇到除了'\*'之外的通配符都是false，因为没有字符。
- p[j]遇到'\*'则与前面第二个的匹配情况 dp[0][j] = dp[0][j - 2],因为'\*'可以表示前一个通配符重复0次。

dp数组计算
- 如果s[i] == p[j] 或者 p[j] == '.'，则dp[i+1][j+1]=dp[i][j]
- 如果p[j] == '\*'
-   如果p[j-1]!=s[i] 且 p[j-1] != '.'则dp[i+1][j+1] = dp[i+1][j-1],相当于少了前一个通配符
-   否则dp[i+1][j+1]=dp[i+1][j] || //前一个通配符仅匹配一次
-                   dp[i][j+1] || //通配符多用一次
-                   dp[i+1][j-1]  //不匹配前一个通配符

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        int mx = plen + 1;//方便数组计算
        if (slen == 0&& plen == 0)
        {
            return 1;
        }

        int *dp = new int[(slen + 1) * (plen + 1)]();//dp[i * mx + j]
        dp[0] = 1;
        for (int i = 1; i < plen; i++)
        {
            if (p[i] == '*'&& dp[i - 1])
            {
                dp[i + 1] = 1;
            }
        }
        for (int i = 0; i < slen; i++)
        {
            for (int j = 0; j < plen; j++)
            {
                if (s[i] == p[j]||p[j] == '.')
                {
                    dp[(i+1) * mx + j + 1] = dp[i * mx + j];
                }
                else if (p[j] == '*')
                {
                    if (s[i] != p[j - 1]&& p[j - 1] != '.')
                    {
                        dp[(i+1) * mx + j + 1] = dp[(i+1) * mx + j - 1];
                    }
                    else
                    {
                        dp[(i+1) * mx + j + 1] = dp[(i+1) * mx + j] + dp[i * mx + j + 1] + dp[(i+1) * mx + j - 1];
                        dp[(i+1) * mx + j + 1] = dp[(i+1) * mx + j + 1] > 1 ? 1 : dp[(i+1) * mx + j + 1];
                    }
                }
            }
        }
        return dp[(slen+1) * (plen+1) - 1];
    }
};
```