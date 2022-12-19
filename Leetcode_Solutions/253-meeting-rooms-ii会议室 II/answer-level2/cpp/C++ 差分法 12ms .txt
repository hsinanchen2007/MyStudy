![image.png](https://pic.leetcode-cn.com/4f9218e7ce39cb6fce892f0192c4168c674947f9cde31a2974af5cca02ca8725-image.png)

思路是差分法，跟1109. 航班预订统计比较类似的题目
直接就理解为每个时间段开始+1，结束时-1，然后累加就OK了
一开始用map处理，因为每次插入都会导致排序，貌似会比较慢一点，因此自定义结构体用vector只排序一次

```
struct record {
    int time = 0;
    int count = 0;
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        records_.reserve(intervals.size() * 2);
        for (const auto& interval : intervals) {
            records_.emplace_back(record{interval[0], 1});
            records_.emplace_back(record{interval[1], -1});
        }
        sort(records_.begin(), records_.end(), [](const auto& a, const auto& b) { return a.time < b.time; });

        int max = 0;
        int pre = 0;
        int time = 0;
        for (auto& record : records_) {
            if (record.time != time) {
                time = record.time;
                if (max < pre) {
                    max = pre;
                }

            }
            pre += record.count;

        }
        return max;
    }
private:
    vector<record> records_;
};
```




