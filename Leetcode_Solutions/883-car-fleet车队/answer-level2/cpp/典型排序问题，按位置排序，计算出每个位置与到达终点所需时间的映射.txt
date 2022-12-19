### 解题思路
典型排序问题，按位置排序，计算出每个位置与到达终点所需时间的映射。这里学习其他大佬的一个小技巧，采用负数位置，这样默认的从小到大排序的set就转换成从大到小排序了

### 代码

```cpp
class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int res=0;
		if (position.empty() || speed.empty()||position.size()!=speed.size()) return 0;
		set<pair<int, double>> pos_time; 
		for (int i = 0; i < position.size(); i++) {
			double time = (double)(target - position[i]) / ((double)(speed[i]));
			pos_time.insert({ -position[i],time });   //采用负数，从而直接排序//按离目的地近到远排序
		}
		vector<double> times;
		for (auto s : pos_time) {
			times.push_back(s.second);
		}
		double cur = 0;
		for (auto a : times) {
			if (a <= cur) continue;
			cur = a;
			++res;
		}

		return res;
	}
};
```