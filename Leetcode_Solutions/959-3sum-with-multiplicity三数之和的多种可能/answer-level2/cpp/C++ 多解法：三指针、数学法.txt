# 解法一：
三指针法
```C++ []
class Solution {
public:
    const long M = 1e9 + 7;
    int threeSumMulti(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int N = A.size();
        long res = 0;
        for (int i = 0; i < N - 2; ++i) {
            int t = target - A[i];
            if (t < 2 * A[i]) break;
            int l = i + 1;
            int r = N - 1;
            while (A[l] < A[r]) {
                if (A[l] + A[r] > t) {
                    --r;
                } else if (A[l] + A[r] < t) {
                    ++l;
                } else {
                    int tl = l;
                    int tr = r;
                    while (A[++l] == A[tl]);
                    while (A[--r] == A[tr]);
                    res += (l - tl) * (tr - r);
                    res %= M;
                }
            }
            if (A[l] == A[r] && A[l] + A[r] == t) {
                int d = r - l + 1;
                res += d * (d - 1) / 2;
                res %= M;
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/7ec5b4b2dd5db9628770d47cad40421131c4300fdf9b13bf8ccb6a6155628c0e-image.png)

# 解法二：
数学法：
```
class Solution {
public:
    const int M = 1e9 + 7;
    int C(long n, long m) {
        if (m == 0) return 1;
        if (m == 1) return n;
        if (m == 2) return (n * (n - 1) / 2) % M;
        return (n * (n - 1) * (n - 2) / 6) % M;
    }
    set<vector<int> > twoSum(map<int, int>& m, int target, int low) {
        set<vector<int> > res;
        int mid = target / 2;
        for (auto& p : m) {
            if (p.first < low || p.second == 0) continue;
            if (p.first > mid) break;
            if ((target == 2 * p.first && p.second >= 2) || 
                    (target != 2 * p.first && m.count(target - p.first) > 0)) {
                res.insert({p.first, target - p.first});
            }
        }
        return res;
    }
    int threeSumMulti(vector<int>& A, int target) {
        map<int, int> m;
        for (auto x : A) ++m[x];
        set<vector<int> > s;
        int min_val = target / 3;
        for (auto& p : m) {
            if (p.first > min_val) break;
            --p.second;
            auto t = twoSum(m, target - p.first, p.first);
            for (auto x : t) {
                x.insert(x.begin(), p.first);
                s.insert(x);
            }
            ++p.second;
        }
        int res = 0;
        for (auto& v : s) {
            map<int, int> t;
            for (auto x : v) ++t[x];
            int n = 1;
            for (auto p : t) {
                n *= C(m[p.first], p.second);
            }
            res += n;
        }
        return res;
    }
};
```

