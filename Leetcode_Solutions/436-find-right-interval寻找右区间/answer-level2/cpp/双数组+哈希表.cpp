官方题解方法五的C++实现。

```
vector<int> findRightInterval(vector<vector<int>>& intervals) {
	vector<int>l_point, r_point;
	vector<int> res(intervals.size(), -1);
	unordered_map<int, int>l_map;
	unordered_map<int, vector<int>>r_map;
	// 分别存储区间的左右端点
	for (auto i : intervals) {
		l_point.push_back(i[0]);
		r_point.push_back(i[1]);
	}
	sort(l_point.begin(), l_point.end());
	sort(r_point.begin(), r_point.end());

	// 由于区间左点端点不重合 ，key分别是区间左端点，val分别区间的索引
	// 由于区间右点端点不重合 ，key分别是区间左端点，val分别区间的索引vector
	for (int i = 0; i < intervals.size(); i++) {
		l_map[intervals[i][0]] = i;
		r_map[intervals[i][1]].push_back(i);
	}

	int l_idx = 0, r_idx = 0;
	while (l_idx < intervals.size() && l_point[l_idx] < r_point[r_idx]) {
		l_idx++;
	}
	while (l_idx < intervals.size() && r_idx < intervals.size()) {
		if (r_point[r_idx] <= l_point[l_idx]) {
			// 使用hash map查找区间的索引
			res[r_map[r_point[r_idx]].back()] = l_map[l_point[l_idx]];
			r_map[r_point[r_idx]].pop_back();
			r_idx++;
		}
		else {
			l_idx++;
		}
	}

	return res;
}
```
