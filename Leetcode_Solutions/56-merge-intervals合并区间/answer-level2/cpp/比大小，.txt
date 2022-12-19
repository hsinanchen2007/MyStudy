### 解题思路
先对intervals排序，使前区间小的数排在前面。
把第一个区间压进去。
intervals[i][0]<=res.back()[1]这里是和res最后一个区间的后区间比较。


### 代码

```cpp
class Solution {
public:
    //执行用时 :44 ms, 在所有 C++ 提交中击败了28.97% 的用户
    //内存消耗 :10.5 MB, 在所有 C++ 提交中击败了100.00%的用户
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i=1;
        res.push_back(intervals[0]);//先把第一个数组压进去
        while(i<intervals.size()){
            while(i<intervals.size()&&intervals[i][0]<=res.back()[1]){//当后一个数组的第一个数大于res最后一个数组的第二个数，就把res最后一个数组的第二个数换了。
                res.back()[1] = max(intervals[i][1],res.back()[1]);
                ++i;
            }
            if(i<intervals.size())//若此时还没到最后一个数组。就先压入res。
                res.push_back(intervals[i++]);
        }
        return res;
    }
};
```