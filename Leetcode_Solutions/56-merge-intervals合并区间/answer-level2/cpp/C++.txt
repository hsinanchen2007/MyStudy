### 解题思路
按照左边界排序，维护前一个区间的左右边界，
然后遍历，如果发现当前区间左边界小于等于前一个区间的右边界，则更新下前一个区间的有边界;
如果当前区间和前一个区间没有交集，意味着前一个区间需要加入到答案中，
最后需要把剩下的最后一个区间加入到答案中

### 代码

```cpp
class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size <= 1) {
            return intervals;
        }
        // 先按照左边界进行排序
        sort(intervals.begin(), intervals.end(), cmp);

        // 存放最后的结果
        vector<vector<int>> ans;

        int preStart = intervals[0][0];
        int preEnd = intervals[0][1];

        for (int i = 1; i < size; i++) {

            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            if (curStart <= preEnd) {
                //　当前起始比上一个区间的末尾还小，需要合并
                preEnd = max(preEnd, curEnd);
            } else {
                // 当前区间与上一个区间没有交集，上一个区间需要加入到答案zhong
                vector<int> tmp = {preStart, preEnd};
                ans.push_back(tmp);
                // 更新
                preStart = curStart;
                preEnd = curEnd;
            }
        }
        vector<int> tmp1 = {preStart, preEnd};
        ans.push_back(tmp1);
        return ans;
    }
};
```