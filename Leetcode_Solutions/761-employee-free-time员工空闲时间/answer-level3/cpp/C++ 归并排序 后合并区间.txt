因为题目里面说每个员工的区间已排好序，所以就利用这个条件，先对员工进行两两合并，两两合并的时候利用已经排好序的特点，O(n)就能排序完成，最后再求补集


```
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        if (schedule.empty()) return {};
        vector<Interval> res = mergeInterval(schedule, 0, schedule.size() - 1);
        if (res.size() < 2) return {};
        vector<Interval> ans;
        for (int i = 1; i < res.size(); ++i) {
            if (res[i].start > res[i-1].end) {
                ans.push_back({res[i-1].end, res[i].start});
            }
        }
        return ans;
    }

    vector<Interval> mergeInterval(vector<vector<Interval>>& schedule, int start, int end) {
        if (start == end) return schedule[start];
        if (start + 1 == end) return merge(schedule[start], schedule[end]);
        int mid = start + (end - start) / 2;
        vector<Interval> left = mergeInterval(schedule, start, mid);
        vector<Interval> right = mergeInterval(schedule, mid + 1, end);
        return merge(left, right);
    }
 
    vector<Interval> merge(vector<Interval>& a, vector<Interval>& b) {
        vector<Interval> tmp;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            tmp.push_back(a[i].start < b[j].start ? a[i++] : b[j++]);
        }
        while (i < a.size()) tmp.push_back(a[i++]);
        while (j < b.size()) tmp.push_back(b[j++]);
        vector<Interval> ans;
        ans.push_back(tmp[0]);
        for (int k = 1; k < tmp.size(); ++k) {
            Interval& last = ans.back();
            if (tmp[k].start <= last.end) {
                last.start = min(last.start, tmp[k].start);
                last.end = max(last.end, tmp[k].end);
            } else {
                ans.push_back(tmp[k]);
            }
        }
        return ans;
    }

};
```
