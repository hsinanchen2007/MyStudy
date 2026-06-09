```c++
bool cmp(int a, int b) {
	return a < b;
}
class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end(), cmp);
		dfs(0, target, 0, candidates);
		return ans;
	}
	int dfs(int sum, int target,int index, vector<int>& candidates) {
		for (int i = index; i < candidates.size(); i++) {
			if (sum + candidates[i] == target) {
				temp.push_back(candidates[i]);
				ans.push_back(temp);
				return 1;
			}
			else if (sum + candidates[i] < target) {
				temp.push_back(candidates[i]);
				int flag=dfs(sum + candidates[i], target, i, candidates);
				if (flag == 0) {
					temp.pop_back();
				}
				else {
					temp.pop_back();
					temp.pop_back();
				}
			}
		}
		return 0;
	}
};
```
