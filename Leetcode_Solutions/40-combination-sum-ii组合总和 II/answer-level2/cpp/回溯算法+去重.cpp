### 解题思路
与39题对比，就是要加入去重部分与每个元素只能用一次
### 代码

```cpp
class Solution {
private:
	vector<int> candidates;
	vector<vector<int>> res;
	vector<int> path;
public:
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = start;
			i < candidates.size() && target - candidates[i] >= 0; i++) {
			if (i > start) { if (candidates[i - 1] == candidates[i]) { continue; } }
			path.push_back(candidates[i]);
			DFS(i + 1, target - candidates[i]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		DFS(0, target);

		return res;
	}

};
```