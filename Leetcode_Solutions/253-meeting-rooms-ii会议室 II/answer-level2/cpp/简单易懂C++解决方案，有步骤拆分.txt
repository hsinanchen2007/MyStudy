### 解题思路

按会议的开始时间进行排序，每次在安排会议时首先考察是否存在已经安排的会议有结束，并且记录结束的会议数目，仅当已经安排的会议都在进行时才安排新的会议室。下面进行步骤分解。

#### 对会议按开始时间进行排序

这里我们使用库函数`sort`：

```cpp
sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
    return lhs[0] < rhs[0];
});
```

#### 记录已经安排的会议的结束情况

为了方便判断是否有已安排的会议结束，我们把已经安排的会议保存在一个最小堆，按照区间的结束时间进行排序，这基于结束时间越小越有可能结束。

堆的定义：

```cpp
// use a min-heap to store running meetings
auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
    return lhs[1] > rhs[1]; // cause the meeting with smallest end time to appear as the top
};
priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
```

初始化：

对于第一个会议，毫无疑问我们需要安排一个会议室，并将其置入堆中：

```cpp
// push the first interval to the heap
pq.push(intervals[0]);

// a room is assigned
int res = 1;
// no room is released
int released = 0;
```

统计已经结束的会议：

```cpp
while (!pq.empty()) {
    int e = pq.top()[1];
    if (e <= s) {
        released++;
        pq.pop();
    } else {
        // all meetings are running
        break;
    }
}
```

分配新的会议室前先考察`released`:

```cpp
if (released == 0) res++; // assign a room if and only if no room is available
else --released;
pq.push(intervals[i]);
```

### 代码

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });
        // use a heap to store running meetings
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] > rhs[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push(intervals[0]);
        
        int res = 1;
        int released = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            int s = intervals[i][0];
            if (released == 0) {
                while (!pq.empty()) {
                    int e = pq.top()[1];
                    if (e <= s) {
                        released++;
                        pq.pop();
                    } else {
                        // all meetings are running
                        break;
                    }
                }
            }
            if (released == 0) res++; // assign a room if and only if no room is available
            else --released;
            pq.push(intervals[i]);
        }
        
        return res;
    }
};
```