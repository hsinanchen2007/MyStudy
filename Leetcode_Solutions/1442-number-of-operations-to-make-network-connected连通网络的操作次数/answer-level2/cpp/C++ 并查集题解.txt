### 代码

```cpp
class Solution {
public:
    vector<int> F;
    int father(int x) {
        if (x != F[x]) F[x] = father(F[x]);
        return F[x];
    }
    void unite(int i, int j) {
        int f1 = father(i);
        int f2 = father(j);
        if (f1 != f2) {
            F[f2] = f1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        F.resize(n);
        for (int i = 0; i < n; ++i) F[i] = i;
        for (auto& con : connections) {
            unite(con[0], con[1]);
        }
        vector<int> group(n, 0);
        for (int i = 0; i < n; ++i) {
            group[father(i)] = 1;
        }
        int g = 0;
        for (int i = 0; i < n; ++i) {
            g += group[i];
        }
        if (g == 1) return 0;
        int l = connections.size();
        if (l < n - 1) return -1;
        return g - 1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/f4b4a1f204b89c279bcd1973cada425fea0cffa91fc33d717d6d2d0bcdb11d11-image.png)
