### 解题思路
1、每个气球（线段）按起点升序排列
2、初始只有一支箭，可射爆排序后的第一个气球
3、找第一个气球和第二个气球有无交集，有则将其交集更新为个新的气球（线段），这两个有交集的气球用同一支箭就可以射爆；如果没有交集，则需要添加一支箭，并且更新当前气球（线段）为后一个气球；
4、直到遍历完所有气球

时间复杂度O(N) + 排序时间
空间复杂度O（1） + 排序空间复杂度


### 代码

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        if (points.size() == 1) return 1;

        // 按起点升序排序
        std::sort(points.begin(), points.end(), 
            [&](const std::vector<int>& pt1, const std::vector<int>& pt2)->bool
            {
                return (pt1[0] < pt2[0]);
            });

        int cnt = 1;
        // 相邻两个求交集
        int x1 = points[0][0];
        int x2 = points[0][1];
        for (int i = 1; i < points.size(); ++i)
        {
            // 无交集
            if (points[i][0] > x2)
            {
                ++cnt;
                x1 = points[i][0];
                x2 = points[i][1];
            }
            // 有交集
            else
            {
                x1 = points[i][0];;
                x2 = min(points[i][1], x2);
            }
        }

        return cnt;
    }
};
```