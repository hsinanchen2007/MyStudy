```
class Solution {
public: 
    int bitLen(int n) {
        int res = 0;
        while (n > 0) {
            ++res;
            n >>= 1;
        }
        return max(res, 1);
    }
    bool queryString(string S, int N) {
        if (N == 0) return true;
        int k = bitLen(N);
        if (k > S.size()) return false;
        long h = 0;
        for (int i = 0; i < k; ++i) {
            h <<= 1;
            h |= S[i] - '0';
        }
        if (h == N) return queryString(S, N - 1);
        for (int i = k; i < S.size(); ++i) {
            h <<= 1;
            h |= S[i] - '0';
            h &= ~((S[i - k] - '0') << k);
            if (h == N) return queryString(S, N - 1);
        }
        return false;
    }
};
```

![image.png](https://pic.leetcode-cn.com/56fa492d3ecec05ecac1f68afd5736232329938c0fe9b8449955d5f3d511ae8d-image.png)
