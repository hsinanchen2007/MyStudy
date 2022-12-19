```
class Solution {
private:
  priority_queue<int, vector<int>, less<int>> end_big; // 结束时间大根堆
  priority_queue<int, vector<int>,greater<int>> end_small; //结束时间小根堆
  priority_queue<int, vector<int>, greater<int>> start_small; //开始时间小根堆
  priority_queue<int, vector<int>, less<int>> start_big; //开始时间大根堆
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
      return true;
    }
    start_small.push(intervals[0][0]);
    end_big.push(intervals[0][1]);
    start_big.push(intervals[0][0]);
    end_small.push(intervals[0][1]);
    for (size_t i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] >= end_big.top() || intervals[i][1] <= start_small.top()) { 
        //当前会议开始晚于最晚开始的会议 或者 当前会议结束早于最早开始的会议
        // 这种情况下 新的会议在当前存在的会议列表的最左边或者最右边
        start_small.push(intervals[i][0]);
        end_big.push(intervals[i][1]);
        start_big.push(intervals[i][0]);
        end_small.push(intervals[i][1]);
      }
      else if (intervals[i][0] >= end_small.top() && intervals[i][1] <= start_big.top()) {
        //当前会议开始时间晚于最早结束的会议并且结束时间早于最早开始的会议
        // 这种情况下 新的会议在会议列表的中间
        start_small.push(intervals[i][0]);
        end_big.push(intervals[i][1]);
        start_big.push(intervals[i][0]);
        end_small.push(intervals[i][1]);
      }
      else {
        // 发生重叠
        return false;
      }
    }
    return true;
  }
};
```
