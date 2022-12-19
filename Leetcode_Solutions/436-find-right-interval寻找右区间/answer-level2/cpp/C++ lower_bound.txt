偷懒直接用lower_bound.....
自己写的话，可以将lower_bound换成排序加二分
```
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mmap;
        for (int i=0; i<intervals.size(); i++) {
            mmap[intervals[i][0]] = i;
        }
        vector<int> res;
        for (int i=0; i<intervals.size(); i++) {
            auto iter = mmap.lower_bound(intervals[i][1]);
            if (iter != mmap.end()) {
                res.emplace_back(iter->second);
            } else {
                res.emplace_back(-1);
            }
        }
        return res;
    }
};
```