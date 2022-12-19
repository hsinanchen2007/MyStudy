```C++ []
class Solution {
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        ll res = 0;
        ll m = 1;
        for (int i = 0; i < A.size(); ++i) {
            res += A[i] * m;
            res %= M;
            m <<= 1;
            m %= M;
        }
        m = 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            res -= A[i] * m;
            res %= M;
            m <<= 1;
            m %= M;
        }
        res = (res + M) % M;
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/7a24aeab599cb3050a6e39e2a46f3b4e3ebe46d23b8ad2d89bd42cb2e0ef9243-image.png)
