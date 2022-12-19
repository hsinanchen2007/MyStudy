### 解题思路
首先通过排序保证遍历时相邻的区间在附近，因为我们要找到需要去掉的最少的区间，也就是要让后一个区间的左边离前一个区间的右边尽量远，这样重叠就可以尽量少，那么要去掉的也就少了。如果碰到重叠的部分我们直接加1就可以，因为此时要么去掉前面的要么去掉后面的，如果前面的右区间小，那么就是去掉后面，如果后面的右区间小，那么就是去掉前面，都是+1。

### 代码

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int left = intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; ++i)
        {
            if(intervals[i][0] < left)
            {
                ans++;
                left = min(left, intervals[i][1]);
            }
            else
                left = intervals[i][1];
        }
        return ans;
    }
};
```