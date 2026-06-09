```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 确定 插入区间的位置
        int left = 0;
        int right = intervals.size() - 1;
        // 由于已经排序好，利用二分法确定插入的元素
        while (left <= right) {
            int mid = (left + right) / 2;
            if (newInterval[0] == intervals[mid][0]) {
                // 把左区间相同的元素直接插入到后面
                left = mid + 1;
                break;
            } else if (newInterval[0] < intervals[mid][0]) {
                right = mid - 1;
            } else if (newInterval[0] > intervals[mid][0]) {
                left = mid + 1;
            }
        }
        // 将区间插入到找到的相应的位置中
        intervals.insert(intervals.begin() + left, newInterval);
        // 找到插入位置后，通常要与前面的元素比较，思考边界条件，可能插入到首个元素，故开始进行重叠区间
        // 判断的时候，需要判断下，其从 index - 1 的位置，还是当前index 的位置
        int k = left == 0 ? 0 : left - 1;
        // 如果当前为空区间的话，可能导致，对下标k的访问越界 -1
        // 从插入区间的前一个位置，开始合并重叠的区域
        for (int i = left; i < intervals.size(); i++) {
            if (intervals[k][1] >= intervals[i][0]) {
                intervals[k][1] = intervals[k][1] > intervals[i][1] ?
                                intervals[k][1] : intervals[i][1];
            } else {
                k++;
                intervals[k] = intervals[i];
            }
        }
        intervals.erase(intervals.begin() + k + 1, intervals.end());
        return intervals;
    }
};
```
