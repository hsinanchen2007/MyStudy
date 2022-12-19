### 解题思路
该题解法和767重构字符串一样的。最大堆的思想。
首先我们使用hashMap建立编码code和出现次数count的映射关系。由于希望将出现次数多的放在前面，所以使用最大堆优先队列priority_queue<次数，编码>。
好了，现在开始拆分重组。首先从队列中取出栈顶的两对子，组合肯定不是相同的啦，但是这两对子映射的次数减一重新放回队列中，直到队列中对子少于2对。
最后，如果队列还剩一个对子，那直接放置在输出码末尾，可以肯定，改对子映射的出现次数只能为1.

### 代码

```cpp
class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> res;
		unordered_map<int, int> m;  //code, counts;
		priority_queue<pair<int, int>> bq;  //counts, code;
		for (auto c : barcodes)++m[c];
		for (auto i : m) {
			//if (i.second > (barcodes.size() + 1) / 2) return -1;
			bq.push({ i.second,i.first });
		}
		while (bq.size() >= 2) {
			auto t1 = bq.top(); bq.pop();
			auto t2 = bq.top(); bq.pop();
			res.push_back(t1.second);
			res.push_back(t2.second);

			if (--t1.first > 0) bq.push(t1);
			if (--t2.first > 0) bq.push(t2);
		}
		if (bq.size() > 0) res.push_back(bq.top().second);
		return res;
	}
};
```