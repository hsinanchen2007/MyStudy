```
class Solution {
public:
    using ll = long long;
    const ll MAX_N = 1e15;
    ll countZero(ll n) {
        ll res = 0;
        while (n > 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
    ll bisearchLeft(int k) {
        ll l = 0;
        ll r = MAX_N;
        while (l < r) {
            ll m = l + (r - l) / 2;
            ll c = countZero(m);
            if (c < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
    ll bisearchRight(int k) {
        ll l = 0;
        ll r = MAX_N;
        while (l < r) {
            ll m = l + (r - l + 1) / 2;
            ll c = countZero(m);
            if (c <= k) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
    int preimageSizeFZF(int K) {
        ll l = bisearchLeft(K);
        ll r = bisearchRight(K);
        return r - l + 1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/55044211ec1c77754fcc9fe9b4d57acff1c896d98a72ebea51d8fa80cc24128e-image.png)
