主要找到规律
```cpp
class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		/*从后往前遍历*/
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			/*如果找到比nums[i]大的数就交换，再把后面的排序*/
			for (int j = nums.size() - 1; j > i; --j)
			{
				if (nums[i] < nums[j])
				{
					swap(nums[i], nums[j]);
					sort(nums.begin() + 1 + i, nums.end());
					return;
				}
			}
		}
		/*说明nums已经是升序结构*/
		sort(nums.begin(), nums.end());
	}
};
```