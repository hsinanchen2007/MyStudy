```C++ []
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        if (A.size() < 2) return false;
        // 从大到小排序
        sort(A.begin(), A.end(), greater<int>());
        if (A[0] == 0) return true;
        int N = A.size();
        if (A.back() != 0) {
            int g = A[0];
            for (auto x : A) g = __gcd(g, x);
            for (auto& x : A) x /= g;
        }
        int S = accumulate(A.begin(), A.end(), 0);
        if (__gcd(S, N) == 1) return false;
        if (A[1] * (N - 1) < S - A[1]) return false;
        int M = 1 << N;
        for (int i = 1; i < M - 1; ++i) {
            int k = 0;
            int s = 0;
            for (int j = 0; j < N; ++j) {
                if (i >> j & 1) {
                    ++k;
                    s += A[j];
                }
            }
            if (S * k == s * N) return true;
        }
        return false;
    }
};
```

![image.png](https://pic.leetcode-cn.com/19cb19d379a377dcffc2c1535c7f04ab3875764667774f76abaabb804a17563d-image.png)
