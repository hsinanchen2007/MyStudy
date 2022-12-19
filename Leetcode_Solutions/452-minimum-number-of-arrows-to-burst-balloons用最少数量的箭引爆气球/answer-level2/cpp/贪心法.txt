### 解题思路
根据是否有重叠，决定是否增加箭。
1.有重叠，points[i][0] <= shoot_end,更新结束坐标min(points[i][1], shoot_end);
2.无重叠，points[i][0] > shoot_end，增加箭数，同时更新结束坐标。

### 代码

```cpp
class Solution {
public:
    int min(int &a, int &b)
    {
        return a>b? b:a;
    }
    int findMinArrowShots(vector<vector<int> >& points) {
        if(points.size() == 0 )
        {
            return 0;
        }
        sort(points.begin(),points.end());
        int shootnum = 1;//至少一次
        int shoot_end = points[0][1];
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > shoot_end)
            {
                shoot_end = points[i][1];
                shootnum++;//更新射箭次数
            }else{
                shoot_end = min(points[i][1], shoot_end);//更新结束坐标
            }
        }
        return shootnum;
    }
};
```