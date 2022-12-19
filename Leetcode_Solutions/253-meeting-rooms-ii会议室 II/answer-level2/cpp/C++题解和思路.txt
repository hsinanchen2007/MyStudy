混排开始，结束时间，然后统计最大的重叠数

```
class Solution {
    enum USAGE {
        START = 0,
        END = 1 
    };
    using POINT = pair<int, USAGE>;

public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 所有时间混在一起排序，pair中第二项表示这个时间是开始还是结束
        vector<POINT> points;
        for (const auto &item : intervals) {
            points.emplace_back(make_pair(item[0], START));
            points.emplace_back(make_pair(item[1], END));
        } 

        // 如果两个时间点相同，那么结束时间需要排在前面，就是先下后上的道理
        sort(begin(points), end(points), [](POINT a, POINT b) {
            if (a.first == b.first) 
                return a.second > b.second;
            return a.first < b.first;
        });

        // 统计重叠时间段的最大值
        int count = 0, res = 0;
        for (const auto &p : points) {
            count += p.second == START ? 1 : -1;
            res = max(res, count);                
        }
        return res;
    }
};
```
