```
class Solution {
private:
	vector<vector<int>> out;
public:
	void DFS(int preSum, vector<int> candidates,int tar,vector<int> vec)
	{
		int len = candidates.size();
		if (preSum == tar)
		{
			out.push_back(vec);
		}
		else if (preSum > tar)return;
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (!vec.empty())
				{
					if (candidates[i] < vec.back())continue;
				}
				vector<int> newVec = vec;
				newVec.push_back(candidates[i]);
				DFS(preSum + candidates[i], candidates, tar, newVec);
			}
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> vec = {};
		DFS(0, candidates, target,vec);
		return out;
	}
};
```
