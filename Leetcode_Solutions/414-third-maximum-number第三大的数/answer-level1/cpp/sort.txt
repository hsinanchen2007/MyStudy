执行用时 :12 ms, 在所有 C++ 提交中击败了57.13%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	int thirdMax(vector<int>& nums) 
	{
		sort(nums.begin(),nums.end());
		int res, flag = 1;
		res = nums[nums.size()-1];
		for (int i=nums.size() - 2; i>=0; --i)
		{
			if (res != nums[i] && flag < 3)
			{
				res = nums[i];
				++flag;
			}
		}
		if (flag == 3)
			return res;
		else
			return nums[nums.size() - 1];
	}
};
```