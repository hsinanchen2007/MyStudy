```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 思路： 判断和当前区间是否有重叠，如果重叠直接计算left = min(intervals[i][0], newInterval[0])
        //        right = max(intervals[i][1], newInterval[i][1])

        if (intervals.size() == 0)
            return vector<vector<int>> {newInterval};
        
        vector<vector<int>> results;
        int pos = 0;
        int left = newInterval[0];
        int right = newInterval[1];
        while (pos < intervals.size()) {
            if(intervals[pos][0] > right) {  // [left, right] 在当前区间左边, 将[left, right]将入到results, 跳出while
                results.push_back(vector<int> {left, right});
                break;
            }
            else if(intervals[pos][1] < left) {  // [left, right] 在当前区间右边, 加入当前区间，继续
                results.push_back(intervals[pos]);
            } else {
                left = min(left, intervals[pos][0]);  // [left, right] 和当前区间有重叠，更新边界
                right = max(right, intervals[pos][1]);
            }
            pos++;
        }

        if (pos == intervals.size()) {  // 如果到达结尾， 将[left, right]加入到results
            results.push_back(vector<int> {left, right});
        } else {
            for (int i = pos; i < intervals.size(); i++)  // 将剩下的区间加入results
                results.push_back(intervals[i]);
        }

        return results;
    }
};
```
