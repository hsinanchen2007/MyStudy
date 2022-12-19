### 解题思路
题目不难，但处理各种情况，可能会有遗漏，要足够细致才行。

### 代码

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int numDecodings(string s) {
        ll f = 1, g = 1;
        if (s[0] == '0')
            return 0;
        for (int i = 0; i < s.size(); ++i) {
            ll tmp = g * (s[i] == '*' ? 9 : 1);
            if (s[i] == '0')
                tmp = 0;
            if (i > 0) {
                if (s[i - 1] == '*' || s[i - 1] == '1')
                    tmp += f * (s[i] == '*' ? 9 : 1);
                if ((s[i - 1] == '*' || s[i - 1] == '2') && (s[i] == '*' || s[i] <= '6'))
                    tmp += f * (s[i] == '*' ? 6 : 1);
                if (s[i - 1] != '*' && (s[i - 1] > '2' || s[i - 1] == '0') && s[i] == '0')
                    return 0;
            }
            tmp %= MOD;
            f = g;
            g = tmp;
        }
        return g;
    }
};
```