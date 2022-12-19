### 解题思路
1，时间转化为分钟数
2，然后对数字进行排序，进行比较
3，注意头部和尾部时间的比较时需要考虑不同的方向

### 代码

```cpp
class Solution {
public:
    const int DAY_MINUTE = 24 * 60;
    int time2int(const string& t) {
        int hour = stoi(t.substr(0, 2));
        int minute = stoi(t.substr(3, 2));
        return hour * 60 + minute;
    }
    int findMinDifference(vector<string>& timePoints) {
        int N = timePoints.size();
        vector<int> times(N, 0);
        for (int i = 0; i < N; ++i) {
            times[i] = time2int(timePoints[i]);
        }
        sort(times.begin(), times.end());
        int res = min(times[N - 1] - times[0], times[0] + DAY_MINUTE - times[N - 1]);
        for (int i = 1; i < N; ++i) {
            res = min(res, times[i] - times[i - 1]);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a37d39434cb9ccfa269cbb8e5129266af99dc8bf48a4dbc96e939f130a87500f-image.png)
