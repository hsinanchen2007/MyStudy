```C++ []
class Solution {
public:
    // l 代表因子的起始数，保证因子的有序性可以做到天然的去重
    vector<vector<int> > dfs(int n, int l) {
        vector<vector<int> > res;
        for (int i = l; i * i <= n; ++i) {
            if (n % i == 0) {
                res.push_back({n / i, i});
                for (auto v : dfs(n / i, i)) {
                    v.push_back(i);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
    vector<vector<int>> getFactors(int n) {
        return dfs(n, 2);
    }
};
```

![image.png](https://pic.leetcode-cn.com/0b3ab36094a9bc9fa78df7b77db4985df16ce784a662060c5ad5c4fcdfa8b575-image.png)
