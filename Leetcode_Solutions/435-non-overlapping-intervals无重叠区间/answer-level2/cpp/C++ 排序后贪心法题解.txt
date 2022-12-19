```
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < left) {
                ++res;
                left = min(left, intervals[i][1]);
            } else {
                left = intervals[i][1];
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/45f99de4b26536e5452fdc71ffeabd582533a5178ffeee4b07a7d5292b86026d-image.png)

