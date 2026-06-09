```
//重载运算符 用于vector排序
bool operator< (const vector<int>& v1, const vector<int>& v2) {
  return v1[0] < v2[0];
}


class Solution {

public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    sort(intervals.begin(), intervals.end());
    priority_queue<int,vector<int>,greater<int>>heap;
    heap.push(intervals[0][1]);
    for (size_t i = 1; i < intervals.size(); i++)
    {
      auto end = heap.top();
      if (end <= intervals[i][0]) {
        heap.pop();
        heap.push(intervals[i][1]);
      }
      else {
        heap.push(intervals[i][1]);
      }
    }
    return heap.size();
  }
};
```
