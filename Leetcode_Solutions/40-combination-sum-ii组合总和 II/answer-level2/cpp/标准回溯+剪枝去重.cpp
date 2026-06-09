### 解题思路
重点在于剪枝去重操作
if (i != begin && candidates[i] == candidates[i - 1])
	{
		continue;	//剪枝
	}

### 代码

```cpp
class Solution 
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
	{
		vector<vector<int>> res;
		vector<int> temp;
        sort(candidates.begin(), candidates.end());		//排序便于剪枝去重
		backtrack(res, temp, candidates, target, 0, 0);
		return res;
	}

	void backtrack(vector<vector<int>> &res, vector<int> temp, vector<int> candidates, int target, int sum, int begin)
	{
		if (sum >= target)
		{
			if (sum == target)
			{
				res.push_back(temp);
			}
		}
		else
		{
			for (int i = begin; i < candidates.size(); ++i)
			{
                if (i != begin && candidates[i] == candidates[i - 1])
				{
					continue;	//剪枝
				}
				temp.push_back(candidates[i]);
				backtrack(res, temp, candidates, target, sum + candidates[i], i + 1);
				temp.pop_back();
			}
		}
	}
};
```