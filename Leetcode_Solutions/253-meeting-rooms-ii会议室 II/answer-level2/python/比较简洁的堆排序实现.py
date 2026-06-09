### 解题思路
官方题解使用堆的方法。

### 代码
```python3 []
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0

        # 根据会议开始时间排序
        intervals.sort()
        rooms = [intervals[0][0]]   # 房间内保存最早结束时间
        for s, e in intervals:
            if rooms[0] <= s:       # 有空余房间
                heapq.heapreplace(rooms, e)
            else:                   # 没有空余房间
                heapq.heappush(rooms, e)
        return len(rooms)           # 返回房间个数
```
```cpp []
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;

        // 根据会议开始时间排序
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> rooms;
        for (const auto& range : intervals) {
            const int& s = range[0];
            const int& e = range[1];
            if (rooms.empty()) {            // 第一个会议结束时间来初始堆
                rooms.push(e);
                continue;
            } else if (rooms.top() <= s) {  // 有空余房间
                rooms.pop();
                rooms.push(e);
            } else rooms.push(e);           // 没有空余房间
        }
        return rooms.size();                // 返回房间个数
    }
};
```