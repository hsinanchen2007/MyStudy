每一次先判断是前一半有序还是后一半有序，然后再判断target在前一半还是后一半
```cpp
class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;

			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[mid] >= nums[left])	//前一半有序
			{
				if (nums[left] <= target && target <= nums[mid])	//在前一半
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else	//后一半有序
			{
				if (nums[mid] <= target && target <= nums[right])	//在后一半
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};
```