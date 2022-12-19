### 解题思路
逆序排列，然后顺序查找
### 代码

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
		if (nums.size() <= 2)
		{
			return nums[0];
		}
		int thmax = nums[0];
		int num = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] > nums[i])
			{
				thmax = nums[i];
				num++;
				if (num == 3)
				{
					return thmax;
				}
			}
		}
		return nums[0];
    }
};
```