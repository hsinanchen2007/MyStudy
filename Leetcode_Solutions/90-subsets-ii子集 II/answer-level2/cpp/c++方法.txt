### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp;
		res.push_back(temp);
		int len2 = nums.size();
		sort(nums.begin(), nums.end());
		int flag = 0;
		int len = 0;
		int start = 0;
		for (int i = 0; i != len2; i++)
		{
			start = len;
		    len = res.size();
			for (int j = 0; j < len; j++)
			{
				flag = 0;
				if (i != 0)
				{
					if (nums[i] != nums[i - 1])
						flag = 1;
					else
						if (j >= start)
							flag = 1;
				}
				else
				{
					flag = 1;
				}
				if (flag == 1)
				{
					temp = res[j];
					temp.push_back(nums[i]);
					res.push_back(temp);
				}

			}
		}
		return res;
	}
};
```