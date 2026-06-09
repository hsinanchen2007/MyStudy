### 解题思路
这个题的贪心主要在于，寻找最先结束的区间，然后删除与该区间重叠的区间。
为什么最先结束的区间A是最优结果呢?因为如果有区间B右区间比该区间结束的晚，则能够与该区间A重叠的区间势必也会与B重叠，还有可能会重叠新的区间。所以，这个是全局最优结果。

### 代码

```cpp

class Solution {
public:
    //sort()必须时静态成员函数
    static bool cmp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        //按照区间终结点，从小到大排序
        sort(intervals.begin(), intervals.end(),cmp);
        
        //获取最小的，区间终结点
        int end = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            //如果区间的起点，小于上一个区间的终点，说明有交集，要删除
            if (intervals[i][0] < end) {
                ++res;
            } else {
                //没有交集，更新end
                end = intervals[i][1];
            }
        }
        return res;
    }
   
};

```