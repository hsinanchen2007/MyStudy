### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		priority_queue<int> res;
		int cost = 0;
		int N = costs.size();
		for (int i = 0; i < N; i++)
		{
			res.push(costs[i][0] - costs[i][1]);
			cost += costs[i][0];
		}
		for (int i = 0; i < N / 2; i++)
		{
			cost -= res.top();
			res.pop();
		}
		return cost;
	}
};
```