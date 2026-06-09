### 解题思路
与56.合并区间还是很类似的，既然已经拍好序了，我们只需要遍历区间序列，新区间与序列中取出的区间作比较，存在三种情况（新区间在左边，新区间在右边，新区间与区间重叠）

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res{ newInterval };
		if (intervals.empty()) return res;
		for (int i = 0; i < intervals.size(); i++) {
			if (res.back()[1] < intervals[i][0]) {
				res.push_back(intervals[i]);
			}
			else if(res.back()[0] > intervals[i][1])
			{
				res.push_back(intervals[i]);
				swap(res.back(),res[res.size()-2]);
			}
			else
			{
				res.back()[0] = min(res.back()[0], intervals[i][0]);
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
		}
		return res;
	}
};
```