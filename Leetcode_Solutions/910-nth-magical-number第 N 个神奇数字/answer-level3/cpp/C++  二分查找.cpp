```
class Solution {
public:
    using ull = unsigned long long;
    const ull MAX = 1e18;
    const ull M = 1e9 + 7;
    ull count(ull A, ull B, ull c, ull n) {
        return n / A + n / B - n / c;
    }
    int nthMagicalNumber(int N, int A, int B) {
        ull c = A * B / __gcd(A, B);
        ull lo = min(A, B);
        ull hi = MAX;
        while (lo < hi) {
            ull mid = lo + (hi - lo) / 2;
            ull t = count(A, B, c, mid);
            if (t >= N) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi % M;
    }
};
```

![image.png](https://pic.leetcode-cn.com/e2bd38de338d6e55f2fba86e2e0fa5dc100f2f5221861ff775b9bcf6bb28dbea-image.png)
