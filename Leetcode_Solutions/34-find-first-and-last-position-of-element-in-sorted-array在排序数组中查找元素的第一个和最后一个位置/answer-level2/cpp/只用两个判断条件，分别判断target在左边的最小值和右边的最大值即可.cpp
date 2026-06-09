### 解题思路
此处撰写解题思路
二分法的主要思想在于判断目标在左半边还是右半边
因为数组时升序的，所以
1. `if (target <= nums[mid])`，则左边的最小值一定在左半边。否则一定在右半边。二分到最后一个数判断是否与target相等即可
2. `if (target >= nums[mid + 1])`，则右边的最大值一定在右半边。否则一定在左半边。二分到最后一个数判断是否与target相等即可
3. 注意判断mid+1不要超过数组界限即可。
### 代码

```cpp
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            {return vector<int> {-1,-1};}
		int right = nums.size() - 1;
		int left = 0;
		int mid = right / 2;
		int output_right = -1;
		int output_left = -1;
		while (left < right)
		{
			if (target <= nums[mid])
			{
				right = mid;
				mid = (left + right) / 2;
			}
			else
			{
				left = mid + 1;
				mid = (left + right) / 2;
			}
		}
			if (nums[mid] == target)
			{
				output_left = mid;
			}
			else{ output_left = -1; }

		right = nums.size() - 1;
		left = 0;
		mid = right / 2;
		while (left < right)
		{
			if (mid + 1 <= nums.size() - 1)
			{
				if (target >= nums[mid + 1])
				{
					left = mid + 1;
					mid = (left + right) / 2;
				}
				else
				{
					right = mid;
					mid = (left + right) / 2;
				}
			}
			else { break; }
		}
			if (nums[mid] == target)
			{
				output_right = mid;
			}
			else {  output_right = -1; }
		vector<int> result = {output_left,output_right};
		return result;
		}
};
```