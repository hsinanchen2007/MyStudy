### 解题思路
![1.png](https://pic.leetcode-cn.com/afbf45e154f26509d5fd78b9afb90d7053fc41fd25dad4b1c2c291427e719175-1.png)

### 代码

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(!points[0][0])return 0;

        int x = points[0][0];
        int y = points[0][1];
        int res = 0;
        for (auto point : points) {
            res += max(abs(point[0] - x),abs(point[1] - y));

            x = point[0];
            y = point[1];
        }
        return res;
    }
};
```