有点类似于梯度下降
假设有两个变量`x, y`，求解方程 `f(x, y) = z`
当`f(x, y)`相对于x和y都是单调的时候
则可以先固定`x`，求下一个满足条件的`y`边界，然后固定y求下一个满足条件的`x`边界，
这样不断逼近最终解
```
class Solution {
public:
    using ll = long long;
    ll nextK(ll k, ll m, ll N, bool& match) {
        match = false;
        ll lo = k + 1;
        ll hi = N - 1;
        while (lo <= hi) {
            ll md = lo + (hi - lo) / 2;
            ll s = 0;
            for (ll i = 0; i <= m; ++i) {
                if (s > (N - 1) / md) {
                    s = N + 1;
                    break;
                }
                s = s * md + 1;
            }
            if (s == N) {
                match = true;
                return md;
            }
            if (s > N) hi = md - 1;
            else lo = md + 1;
        }
        return lo;
    }
    ll nextM(ll k, ll m, ll N, bool& match) {
        match = false;
        ll lo = 1;
        ll hi = m - 1;
        while (lo <= hi) {
            ll md = lo + (hi - lo) / 2;
            ll s = 0;
            for (ll i = 0; i <= md; ++i) {
                if (s > (N - 1) / k) {
                    s = N + 1;
                    break;
                }
                s = s * k + 1;
            }
            if (s == N) {
                match = true;
                return md;
            }
            if (s > N) hi = md - 1;
            else lo = md + 1;
        }
        return hi;
    }
    string smallestGoodBase(string n) {
        ll N = stoll(n);
        ll k = 2;
        ll m = N; // m为N表示为k进制的最高次幂
        bool match = false;
        while (k < N && m > 0) {
            m = nextM(k, m, N, match);
            if (match) break;
            k = nextK(k, m, N, match);
            if (match) break;
        }
        return to_string(k);
    }
};
```
![image.png](https://pic.leetcode-cn.com/c393dc6e43dc96712d9c0f3cd453ea1b6e7aa64711ccc24a2d1076a6fcd21a31-image.png)
