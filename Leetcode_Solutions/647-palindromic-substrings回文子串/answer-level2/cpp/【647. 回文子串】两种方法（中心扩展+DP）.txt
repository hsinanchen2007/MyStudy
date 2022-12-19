### 思路一：中心扩散
从开始每个字符进行判断，回文串字符个数可能为奇数或偶数
- 如果是奇数，则中心字符为当前字符，然后向两边扩散
- 如果是偶数，则中心字符为当前字符和下一个字符，然后向两边扩散

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int size = s.size(), res = 0;
        for (int i = 0; i < size; ++i) {
            helper(s, i, i, res);
            helper(s, i, i + 1, res);
        }
        return res;
    }

    void helper(string &s, int i, int j, int &res) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i, ++j, ++res;
        }
    }
};
```

### 思路二：DP
dp[i][j]表示[i, j]范围内字符是否为回文串，i从后向前遍历，j从i位置向后遍历，如果s[i] == s[j]，那么i和j满足下面两个条件之一，则dp[i][j] = true。
- 如果i和j相邻或只隔着一个字符，则dp[i][j] = true
- 否则如果dp[i + 1][j - 1] = true，则dp[i][j] = true

### 代码
```c++
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int size = s.size(), res = 0;
        vector<vector<bool>> dp(size, vector<bool>(size));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) ++res;            
            }            
        }
        return res;
    }
};
```
