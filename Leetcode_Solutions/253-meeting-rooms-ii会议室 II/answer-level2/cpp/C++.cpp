### 解题思路
排序：
会议是按照开始时间进行安排，需要按照开始时间排序

堆：
用小顶堆维护每个会议室的结束时间
如果当前会议的开始时间比最小的结束时间大，可以复用一间会议室，把上一个结束时间移除，把新的结束时间加入
否则，需要重新分配一间会议室，新的会议的结束时间入堆

如此可以求得需要多少间会议室

ps. 看了一遍hint,手写两遍过（第一遍忘了pop），记录一下


### 代码

```cpp
class Solution {
public:
    static bool cmp (vector<int>& a, vector<int>& b) {
        // 按开始时间从小到大排序
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {

        // 使用优先队列模拟小顶堆，存储结束时间
        priority_queue<int, vector<int>, greater<int>> pq;

        int size = intervals.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return 1;
        }
        int room = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < size; i++) {
            if (pq.empty()) {
                // 堆空，直接把结束时间入堆
                pq.push(intervals[i][1]);
                room++;
            } else {
                // 堆不空，首先获取堆顶，也就是最早结束时间
                int earliestEnd = pq.top();
                if (earliestEnd > intervals[i][0]) {
                    // 最早结束时间比当前会议时间还晚，需要新分配一间会议室
                    room++;
                    pq.push(intervals[i][1]);
                } else {
                    // 有会议室可以用. room不需要再分配
                    // 先把可用的会议室的结束时间移除
                    pq.pop();
                    pq.push(intervals[i][1]);
                }
            }
        }
        return room;
    }
};
```