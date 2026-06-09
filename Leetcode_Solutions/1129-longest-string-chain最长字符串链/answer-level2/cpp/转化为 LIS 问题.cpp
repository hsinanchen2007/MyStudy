### 解题思路

重定义字符串比较函数，转化为 LIS 问题。

### 代码

```cpp
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs) {
            return lhs.size() < rhs.size();
        });
        
        vector<int> dp(n + 1, 1);
        int ans = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(comp(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
    
    //  a 是 b 的前身
    bool comp(const string& a, const string& b) {
        if(a.size() + 1 != b.size())
            return false;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();
    }
};
```