### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
	int missingNumber(vector<int>& nums) 
	{
		int len = nums.size();
		int flag = (1 + len) * len / 2;
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += nums[i];
		}
		return flag - sum;
	}
};
```