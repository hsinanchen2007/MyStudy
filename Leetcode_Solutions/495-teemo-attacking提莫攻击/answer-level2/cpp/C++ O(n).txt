### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int valid_time = 0;
        for (int i=0; i<timeSeries.size(); i++) {
            if (valid_time>timeSeries[i]) {
                ans += duration - (valid_time-timeSeries[i]);
            } else {
                ans += duration;
            }
            valid_time = timeSeries[i] + duration;
        }
        return ans;
    }
};
```