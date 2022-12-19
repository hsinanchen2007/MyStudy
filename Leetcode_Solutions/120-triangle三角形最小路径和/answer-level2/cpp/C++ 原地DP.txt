```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                int t1 = j < i ? triangle[i - 1][j] : INT_MAX;
                int t2 = j > 0 ? triangle[i - 1][j - 1] : INT_MAX;
                triangle[i][j] += min(t1, t2);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
```
![image.png](https://pic.leetcode-cn.com/e56104e43629031e8316b5d4fc81d31edebebdc08ab6c025b09303920e4c9a78-image.png)


