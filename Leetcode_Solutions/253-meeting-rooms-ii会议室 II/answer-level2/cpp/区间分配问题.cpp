### 解题思路
之前区间分配问题采用贪心算法进行求解，该问题一般都是求解一群区间里面最多有多少个不重合的区间，还有就是射气球问题；这个会议室的分配属于另外一种问题，它并不需要求取出最多有多少个会议可以在同一个会议室里面进行；而是最少可以分成多少组；
求解方式一般都是先按照开始时间进行排序，然后在利用优先队列对结束时间进行筛选，这个过程中的队列最长值就是会议室需要最多的时段。

### 代码

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {	
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
			return a[0] < b[0];
		});
		priority_queue<int, vector<int>, greater<int> > endingTimeUpQueue;
		unsigned int MaxmeetingRoom = 0;
		for (int i = 0; i < intervals.size(); i++) {
			if (endingTimeUpQueue.empty()) {
				endingTimeUpQueue.push(intervals[i][1]);
			} else {
				if (intervals[i][0] >= endingTimeUpQueue.top()) {
					endingTimeUpQueue.pop();
				} 
                endingTimeUpQueue.push(intervals[i][1]);
			}
            if (MaxmeetingRoom < endingTimeUpQueue.size() ) {
                MaxmeetingRoom = endingTimeUpQueue.size();
            }
		}
		return MaxmeetingRoom;
	}
};
```