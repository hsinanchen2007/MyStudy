### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> result;
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> temp;
		findZiJi(nums, 0, temp);
		return result;
	}
	void findZiJi(vector<int>& nums, int start, vector<int>& temp)
	{
		result.push_back(temp);
		map<int, int> levelMap;
		for (int i = start; i < nums.size(); i++)
		{
			if (levelMap[nums[i]] <= 0)
			{
				levelMap[nums[i]] = 1;
				temp.push_back(nums[i]);
				findZiJi(nums, i + 1, temp);
				temp.pop_back();
			}
		}
	}
};
```