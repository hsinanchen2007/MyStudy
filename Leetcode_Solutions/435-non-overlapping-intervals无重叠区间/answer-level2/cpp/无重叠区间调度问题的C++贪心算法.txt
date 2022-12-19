### 解题思路
这个问题有许多看起来不错的贪心思路，却都不能得到正确答案。比如说：
也许我们可以每次选择可选区间中开始最早的那个？但是可能存在某些区间开始很早，但是很长，使得我们错误地错过了一些短的区间。或者我们每次选择可选区间中最短的那个？或者选择出现冲突最少的那个区间？这些方案都能很容易举出反例，不是正确的方案。
正确的思路其实很简单，可以分为以下三步：
* 从区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中结束最早的（end 最小）。
* 把所有与 x 区间相交的区间从区间集合 intvs 中删除。
* 重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。
把这个思路实现成算法的话，可以按每个区间的 end 数值升序排序
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