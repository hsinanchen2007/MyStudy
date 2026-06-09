
### 代码

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 贪心算法
        // 先将所有的气球以start排序
        // 然后找气球在x坐标上重合部分最多的地方射击, 则需要最少的弓箭
        // 也就是找 重合最多的线段区域
        if(points.size() == 0 || points[0].size() == 0)
            return 0;
        sort(points.begin(), points.end());
        int count = 0;
        int start = points[0][0], end = points[0][1];
        for(int i = 1; i < points.size(); ++i){
           if(end >= points[i][0]){             //两种情况的交集
               start = points[i][0];
            if(end >= points[i][1])
                end = points[i][1];
           }
            else{
                count++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        if(start <= end)        //最后一次交错要判断下
            count++; 
        return count;
    }
};
```