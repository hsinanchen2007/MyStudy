### 解题思路
想法比较直接，二分找到区间头部该插入的位置，然后向左右扩展合并区间。
右边情况比较复杂，可能会合并好几个区间，左边因为之前二分定位过了，可以肯定最多向左合并一个区间。
其他就确定边界条件就完事了。
因为直接在vector里处理，又懒。。。所以没有考虑优化在vector里的插入，输出前直接sort√，时间效率看上去也还行，但因为又排序，所以时间复杂度从O(N)降到了O(NlogN)
**（在这里提出一个设想，如果手写一个插入排序，不知道能不能把时间复杂度降成O(N)**
感想：边界条件没别的，就是调试到自闭otz

![image.png](https://pic.leetcode-cn.com/54ef3f0251ef661c909704f73608f8326fbbc614ec42ec838e3477a0653c1968-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0, r = intervals.size() - 1, mid;
        // 判定特殊情况
        if(r < 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        // 二分查找
        while(l < r)
        {
            mid = (l + r) / 2;
            if(intervals[mid][0] < newInterval[0]) l = mid + 1;
            else r = mid;
        }
        // 判定特殊情况，这里是将区间整个插入到原有区间序列的头或尾
        int x = newInterval[0], y = newInterval[1];
        if(intervals[l][0] > y && (l == 0 || l > 0 && intervals[l - 1][1] < x) || intervals[l][1] < x)
        {
            intervals.push_back({x, y});
            sort(intervals.begin(),intervals.end());
            return intervals;
        }
        // 向右合并
        while(r < intervals.size() && intervals[r][0] <= y)
        {
            y = max(y, intervals[r][1]);
            x = min(x, intervals[r][0]);
            r ++;
        }
        //向左合并
        if(l > 0 && intervals[l - 1][1] >= x)
        {
            x = min(x, intervals[l - 1][0]);
            y = max(y, intervals[l - 1][1]);
            l --;
        }
        // 去除已经合并的区间
        intervals.erase(intervals.begin() + l, intervals.begin() + r);
        intervals.push_back({x, y});
        sort(intervals.begin(),intervals.end());
        return intervals;
    }
};
```