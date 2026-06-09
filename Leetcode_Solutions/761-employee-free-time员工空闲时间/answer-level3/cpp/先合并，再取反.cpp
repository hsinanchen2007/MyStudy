从[合并区间](https://leetcode-cn.com/problems/merge-intervals/)过来的，很自然的思路就是先合并，再取反。

```C++[]

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all_interval;
        for(int i = 0; i < schedule.size(); i++){
            for(int j = 0; j < schedule[i].size(); j++){
                all_interval.push_back(schedule[i][j]);
            }
        }
        sort(all_interval.begin(), all_interval.end(), [](const Interval &a, const Interval &b){
            if(a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        vector<Interval> conbine;
        vector<Interval> result;
        int now = 0;
        for(int i = 1; i < all_interval.size(); i++){
            if(all_interval[now].end >= all_interval[i].start){
                all_interval[now].end = max(all_interval[now].end, all_interval[i].end);
            }else{
                conbine.push_back(all_interval[now]);
                now = i;
            }
        }
        conbine.push_back(all_interval[now]);
        for(int i = 0; i < conbine.size() - 1; i++){
            conbine[i].start = conbine[i].end;
            conbine[i].end = conbine[i + 1].start;
            result.push_back(conbine[i]);
        }
        return result;
    }
};
```
