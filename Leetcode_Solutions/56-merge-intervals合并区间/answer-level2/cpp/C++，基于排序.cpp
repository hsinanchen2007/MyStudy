**思路：**
- 先对各个区间按照左边界大小排序。
- 将大区间的左、右边界分别初始化为第1个区间的左、右边界。
- 从第2个区间开始，检查其左边界是否小于等于大区间的右边界；如果是，再检查其右边界是否大于大区间的右边界，以确定是否更新大区间的右边界；如果不是，将大区间作为一个新的合并后的区间保存下来，并使用当前区间的左、右边界初始化下一个大区间的左、右边界。
- 类似地检查每个区间，直至遍历完所有区间。

**时空复杂度：**
时间主要损耗在排序，时间复杂度为O(nlogn)；如果不考虑存储答案所需的空间，则空间复杂度为O(1)

```
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        int size = intervals.size();
        if (size == 0) return ans;

        sort(intervals.begin(), intervals.end(), cmp);

        int a = intervals[0][0], b = intervals[0][1];
        for (int i = 1; i < size; ++i){
            if (intervals[i][0] <= b){ // 左边界是否小于等于大区间的右边界
                b = max(b, intervals[i][1]); // 右边界是否大于大区间的右边界
            }
            else{
                vector<int> tmp = {a,b}; // 将大区间作为一个新的合并后的区间保存下来
                ans.push_back(tmp);

                a = intervals[i][0]; // 使用当前区间的左、右边界初始化下一个大区间的左、右边界
                b = intervals[i][1];
            }
        }
        vector<int> tmp = {a,b}; // 注意考虑最后一个大区间
        ans.push_back(tmp);

        return ans;
    }
};
```
