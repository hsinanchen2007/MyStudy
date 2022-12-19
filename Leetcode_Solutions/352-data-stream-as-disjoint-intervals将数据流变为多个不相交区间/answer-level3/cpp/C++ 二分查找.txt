# 思路
1，维护一个intervals区间
2，然后不断添加数的时候，二分法定位数在区间中的位置
3，更改区间，并输出区间
```C++ []
class SummaryRanges {
public:
    vector<vector<int> > intervals;
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    int bisearchL(int n) {
        int lo = 0;
        int hi = intervals.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (intervals[mid][0] <= n) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
    int bisearchR(int n) {
        int lo = 0;
        int hi = intervals.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][1] >= n) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
    void addNum(int val) {
        if (intervals.empty()) {
            intervals.push_back({val, val});
            return;
        }
        if (val > intervals.back()[1]) {
            if (val == intervals.back()[1] + 1) {
                intervals.back()[1] = val;
            } else {
                intervals.push_back({val, val});
            }
        } else if (val < intervals[0][0]) {
            if (val == intervals[0][0] - 1) {
                intervals[0][0] = val;
            } else {
                intervals.insert(intervals.begin(), {val, val});
            }
        } else {
            int l = bisearchL(val);
            int r = bisearchR(val);
            if (l == r) return;
            if (intervals[l][1] + 2 == intervals[r][0]) {
                intervals[l][1] = intervals[r][1];
                intervals.erase(intervals.begin() + r);
            } else if (intervals[l][1] + 1 == val) {
                intervals[l][1] = val;
            } else if (intervals[r][0] - 1 == val) {
                intervals[r][0] = val;
            } else {
                intervals.insert(intervals.begin() + r, {val, val});
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

```

![image.png](https://pic.leetcode-cn.com/2d05c1229fd21fbffe356374cce51a8dfd5be3af404fab92ea3132649b5f8ebe-image.png)
