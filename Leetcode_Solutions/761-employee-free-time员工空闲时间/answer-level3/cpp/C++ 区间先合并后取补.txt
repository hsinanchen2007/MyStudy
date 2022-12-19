```C++ []
class Solution {
public:
	vector<Interval*> merge(const vector<Interval*>& v1, const vector<Interval*>& v2) {
		if (v1.empty()) return v2;
		if (v2.empty()) return v1;
		vector<Interval*> res;
		int mark = 0;
		int i = 0;
		int j = 0;
		int N1 = v1.size();
		int N2 = v2.size();
		int flag1 = 1;
		int flag2 = 1;
		int left = -1;
		while (i < N1 && j < N2) {
			int t1 = (flag1 == 1) ? v1[i]->start : v1[i]->end;
			int t2 = (flag2 == 1) ? v2[j]->start : v2[j]->end;
			if (t1 == t2) {
				mark += flag1 + flag2;
				flag1 *= -1;
				flag2 *= -1;
				if (flag1 > 0) ++i;
				if (flag2 > 0) ++j;
			} else if (t1 < t2) {
				mark += flag1;
				flag1 *= -1;
				if (flag1 > 0) ++i;
			} else {
				mark += flag2;
				flag2 *= -1;
				if (flag2 > 0) ++j;
			}
			if (mark == 0) {
				res.push_back(new Interval(left, min(t1, t2)));
				left = -1;
			} else if (left == -1) {
				left = min(t1, t2);
			}
		}
		if (i < N1) {
			if (mark > 0) {
				res.push_back(new Interval(left, v1[i]->end));
				++i;
			}
			for (; i < N1; ++i) res.push_back(v1[i]);
		}
		if (j < N2) {
			if (mark > 0) {
				res.push_back(new Interval(left, v2[j]->end));
				++j;
			}
			for (; j < N2; ++j) res.push_back(v2[j]);
		}
		return res;
	}
	vector<Interval*> mergeMulti(const vector<vector<Interval*> >& schedule, int l, int r) {
		if (l > r) return {};
		if (l == r) return schedule[l];
		if (l + 1 == r) return merge(schedule[l], schedule[r]);
		int m = l + (r - l) / 2;
		auto left = mergeMulti(schedule, l, m);
		auto right = mergeMulti(schedule, m + 1, r);
		return merge(left, right);
	}
	vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
		auto v = mergeMulti(schedule, 0, schedule.size() - 1);
		vector<Interval*> res;
		for (int i = 1; i < v.size(); ++i) {
			res.push_back(new Interval(v[i - 1]->end, v[i]->start));
		}
		return res;
	}
};

```

![image.png](https://pic.leetcode-cn.com/b6af9390c167be414a0af27df0f40e123d00dc56cc516e7903a92c69eb54f60b-image.png)
