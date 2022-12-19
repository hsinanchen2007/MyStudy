### 解题思路
先按照左边界排序
然后从第二个开始依次遍历，
如果左边界小于等于上一个区间的右边界，则更新右边界为两个右边界的最大值
如果左边界跟上一个区间的右边界没有交集，则将当前的左右边界写到结果里

### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int> &a1, vector<int> &a2) {
        return a1[0] < a2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 遍历所有区间，找到最大值和最小值
        int size = intervals.size();
        
        // 先按照左边界从小到大排序
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        if(size <= 0) {
            return result;
        }
        int preStart = intervals[0][0];
        int preEnd = intervals[0][1];
        for (int i = 1; i < size; ++i) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            if(curStart <= preEnd) {
                // 和前一个区间有交集
                /*
                vector<int> tmp;
                tmp.push_back(preStart);
                tmp.push_back(max(preEnd, curEnd));
                */
                preEnd = max(preEnd, curEnd);
            } else {
                vector<int> tmp;
                tmp.push_back(preStart);
                tmp.push_back(preEnd);
                result.push_back(tmp);
                preStart = curStart;
                preEnd = curEnd;
            }
        }
        vector<int> tmp;
        tmp.push_back(preStart);
        tmp.push_back(preEnd);
        result.push_back(tmp);
        return result;
    }
};
```