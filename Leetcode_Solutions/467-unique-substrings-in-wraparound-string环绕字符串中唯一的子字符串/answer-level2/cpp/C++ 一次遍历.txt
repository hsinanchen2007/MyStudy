### 解题思路
1，记录以每个字符结尾字串的最长长度
2，然后最终累加即可得结果

### 代码

```cpp
class Solution {
public:
    bool isContinous(char prev, char curr) {
        if (prev == 'z') return curr == 'a';
        return prev + 1 == curr;
    }
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int N = p.size();
        int k = 0;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && isContinous(p[i - 1], p[i])) {
                ++k;
            } else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
```

![image.png](https://pic.leetcode-cn.com/b636921838b0e7e4d94fad731b574b8b57d3936554f8c520fbd258041495d3e4-image.png)
