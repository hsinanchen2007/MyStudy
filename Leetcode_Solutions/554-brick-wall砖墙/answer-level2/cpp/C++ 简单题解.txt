```
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if (wall.empty()) return 0;
        int R = wall.size();
        map<int, int> m;
        for (int i = 0; i < R; ++i) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                ++m[sum];
            }
        }
        int max_count = 0;
        for (auto& p : m) {
            max_count = max(max_count, p.second);
        }
        return R - max_count;
    }
};
```

![image.png](https://pic.leetcode-cn.com/9948040154e0da58223fc9073c82ff59455e801882350ba16d6e06ac414d3a0e-image.png)
