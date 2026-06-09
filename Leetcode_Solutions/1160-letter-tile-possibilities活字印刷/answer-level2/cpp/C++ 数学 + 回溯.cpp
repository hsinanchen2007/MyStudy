```
class Solution {
public:
    using ll = long long;
    ll A(ll n) {
        return n == 0 ? 1 : n * A(n - 1);
    }
    ll A(ll n, ll m) {
        return A(n) / A(m); 
    }
    ll C(ll n, ll m) {
        return A(n, m) / A(n - m);
    }
    void backtrace(vector<int>& counts, vector<int>& selects, int k, int n, ll& res) {
        if (selects.size() == counts.size()) {
            if (k > n || k < 1) return;
            ll t = 1;
            for (auto x : selects) {
                t *= C(k, x);
                k -= x;
            }
            res += t;
            return;
        }
        int ind = selects.size();
        for (int i = 0; i <= min(counts[ind], n); ++i) {
            selects.push_back(i);
            backtrace(counts, selects, k + i, n, res);
            selects.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> counts(26, 0);
        for (auto c : tiles) ++counts[c - 'A'];
        vector<int> selects;
        ll res = 0;
        backtrace(counts, selects, 0, tiles.size(), res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c728448ad71c9ddd6fc8b7c132b80daf66bddca192c9ba54017fecaa5f1ab969-image.png)
