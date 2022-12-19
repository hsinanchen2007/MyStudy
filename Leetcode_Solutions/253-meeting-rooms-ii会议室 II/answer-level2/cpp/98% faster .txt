首先将时间表排序，按照开始时间和结束时间一起，让时间点领先的先发生的。
然后将结果存入到优先级队列中，每次从优先级队列中取出之前所有时间安排中最早结束的，然后观察是否可以合并。

这毕竟符合我们现实中的安排，按时间依次安排，如果现有的会议室都占用，就再申请一间。但是如果在某个会议快要开始的时候，之前的会议快要结束了，那就可以立马占用了。
```cpp
typedef vector<int> vi;
struct cmp {
    bool operator()(const vi& a, const vi& b) {
        return a[1] > b[1];
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<vi, vector<vi>, cmp> pq;
        int ans = 0;
        for (int i = 0; i < intervals.size(); i ++) {
            if (pq.empty()) pq.push(intervals[i]);
            else {
                int cur_s = intervals[i][0], cur_e = intervals[i][1];
                int s = pq.top()[0], e = pq.top()[1];
                if (cur_s >= e) {
                    pq.pop();
                    vi v = {s, cur_e};
                    pq.push(v);
                }
                else  
                    pq.push(intervals[i]);
            }
        }
        return pq.size();
    }
};
```


