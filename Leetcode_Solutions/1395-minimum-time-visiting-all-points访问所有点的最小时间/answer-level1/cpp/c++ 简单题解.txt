比较简单，只需要计算沿着对角线最少移动的距离，其余的用横或纵补齐即可

代码：

```c++
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 1; i < points.size(); ++i) {
            int x_bias = abs(points[i][0] - points[i - 1][0]), 
                y_bias = abs(points[i][1] - points[i - 1][1]);
            res += min(x_bias, y_bias) + abs(x_bias - y_bias);
        }
        return res;
    }
};
```

