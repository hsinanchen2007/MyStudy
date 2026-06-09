![1.png](https://pic.leetcode-cn.com/a8b1529e7ea7032a55f030277997987e9027a47287bba1ea43800a5e4921e3d2-1.png)

### 代码
```cpp
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        vector<vector<int>> res;
        for (int x = 1; x < 1001; ++x) {
            int l = 1;
            int r = 1000;
            while (l < r) {
                int m = (r + l) / 2;
                int cur = cf.f(x, m);

                if (cur == z) {
                    res.push_back({ x,m });
                    break;
                }
                else if (cur > z) r = m;
                else l = m + 1;
            }
        }
        return res;
    }
};
```