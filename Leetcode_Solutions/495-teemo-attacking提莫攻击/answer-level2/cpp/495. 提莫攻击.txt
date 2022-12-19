处理有区间交集的情况，思路看注释

```
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;

        int ans = 0;
        int start = timeSeries[0];
        int end = timeSeries[0] + duration;
        for(int i = 1; i < timeSeries.size(); i++)
        {
            if(timeSeries[i] >= end)  // 如果区间没有重叠，累加结果，再更新区间起点和终点
            {
                ans = ans + end - start; 
                start = timeSeries[i];
                end = timeSeries[i] + duration;
            }
            else
            {
                end = timeSeries[i] + duration; // 如果区间有重叠，更新右边界的值
            }
        }

        ans = ans + end - start; // 处理收尾情况

        return ans;
    }
};
```
