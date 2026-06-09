### 解题思路
首先给区间排序，其次将首个元素存入结果中，随后开始遍历区间集合，如果取出的区间与结果中末尾区间有重合，则重新构造再放回去，否则直接将取出的区间存入结果。

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty()) return{};
		sort(intervals.begin(), intervals.end());//默认从小到大
		vector<vector<int>> res{ intervals[0] };
		for (int i = 1; i < intervals.size(); i++) {
			if (res.back()[1] >= intervals[i][0]) {
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
		else
			{
				res.push_back(intervals[i]);
			}
        }
		return res;
	}
};
```