```
class Solution {
public:
    struct DSU {
        vector<int> F;
        int find(int x) {
            if (F[x] != x) F[x] = find(F[x]);
            return F[x];
        }
        void unite(int x, int y) {
            int f1 = find(x);
            int f2 = find(y);
            F[f1] = F[f2] = min(f1, f2);
        }
        DSU() {
            F = vector<int>(26, 0);
            for (int i = 0; i < 26; ++i) F[i] = i;
        };
    };
    DSU dsu;
    Solution() {
        dsu = DSU();
    }
    string smallestEquivalentString(string A, string B, string S) {
        for (int i = 0; i < A.size(); ++i) {
            dsu.unite(A[i] - 'a', B[i] - 'a');
        }
        string res;
        for (auto x : S) {
            res += dsu.find(x - 'a') + 'a';
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/dec86e6084b82fc376079af13bdbef65b8bb4857d55d53de96b067c497546bb9-image.png)
