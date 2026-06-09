用哈希表存储各数的数量，用只包含k个元素的最小堆找数量最多的元素。
下面代码中用unordered_map来存储数和数量的键值对，用priority_queue来作为堆找数量最多的k个元素，最后将堆中的元素放到返回结果中。
执行用时超过82.39%。

```C++ []
class Solution {
public:
	struct cmp {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
		}
	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		unordered_map<int, int> m;
		for (int num : nums)
			m[num]++;

		priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> q;
		for (auto p : m) {
			q.push(p);
			if (q.size() > k)
				q.pop();
		}

		while (!q.empty()) {
			res.push_back(q.top().first);
			q.pop();
		}
		return res;
	}
};
```
