### 解题思路
按会议开始时间排序
遍历所有的会议室时间，如果已安排会议的结束时间比当前会议开始时间还晚，说明会议冲突，直接返回错误
否则，取当前会议结束时间和lastTime的最大值，作为已安排会议的结束时间。

### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int lastTime = 0; // 最后的会议时间
        for (auto meet : intervals) {
            if (lastTime > meet[0]) {  //如果最后会议时间比将要开的会开始时间还晚，说明有冲突，直接返回false
                return false;
            }
            lastTime = max(lastTime, meet[1]);  //否则更新最后会议时间
        }
        return true;
    }
};
```