### 解题思路
遇到小于duration的直接跳过；
遇到大于duration的进行计算，并更新beginIndex；

### 代码

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        if (timeSeries.size() == 1) {
            return duration;
        }
        int beginIndex = 0;
        int endIndex = 1;
        int count = 0;
        while (endIndex < timeSeries.size()) {
            if (timeSeries[endIndex] - timeSeries[endIndex - 1] <= duration) {
                endIndex++;
            } else{
                count += (timeSeries[endIndex - 1] - timeSeries[beginIndex] + duration);
                beginIndex = endIndex;
                endIndex++;
            }
        }
        count += (timeSeries[endIndex - 1] - timeSeries[beginIndex] + duration);
        return count;
    }
};
```