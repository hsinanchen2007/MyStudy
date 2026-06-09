### 解题思路
题目很长，都是纸老虎。
两个点之间走路消耗的时间实际就是x和y坐标相减之后取绝对值，哪个大就是哪个。
### 头文件
```
#include <iostream>
#include <vector>
#include <cmath>
```

### 代码

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if (points.empty())
            return 0;
        int num=0;
        int length_of_points=points.size();
        for (int i=0; i<length_of_points-1; i++){
            num += max(abs(points[i+1][0]-points[i][0]), abs(points[i+1][1]-points[i][1]));
        }
        return num;
    }
};
```