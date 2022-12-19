### 解题思路
参考官方题解的C++ Rabin-Karp解法

### 代码

```cpp
class Solution {
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    bool valid(const string& s, const vector<ll>& pows, int k) {
        ll n = 0;
        for (int i = 0; i < k; ++i) {
            n = n * 26 + (s[i] - 'a');
            n %= M;
        }
        unordered_map<ll, vector<int> > m;
        m[n].push_back(0);
        ll p = pows[k - 1];
        for (int i = k; i < s.size(); ++i) {
            n = 26 * (n - p * (s[i - k] - 'a')) + (s[i] - 'a');
            n = ((n % M) + M) % M;
            if (m.count(n)) {
                // 重新验证，防止哈希冲突带来假真
                string t = s.substr(i - k + 1, k);
                for (int j : m[n]) {
                    if (s.substr(j, k) == t) {
                        return true;
                    }
                }
            }
            m[n].push_back(i - k + 1);
        }
        return false;
    }
    int longestRepeatingSubstring(string S) {
        vector<ll> pows(S.size(), 1);
        for (int i = 1; i < S.size(); ++i) {
            pows[i] = (pows[i - 1] * 26) % M;
        }
        int lo = 0;
        int hi = S.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (valid(S, pows, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
```

![image.png](https://pic.leetcode-cn.com/e60fe441596b051f048380aef98e3c5931eff6bc84647323ebd1768d6882ee57-image.png)
