### 解题思路
参考自剑指offer解析
二分查找
1、通过二分查找找到第一个k出现的下标，未出现，则返回0
2、通过二分查找找到最后一个k出现的下标，未出现，则返回0


### 代码

```cpp
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size()==0)
		{
			return 0;
		}
		int first = getFirst(nums, target, 0, nums.size() - 1);
		int last = getLast(nums, target, 0, nums.size() - 1);
		if (first>-1&&last>-1)
		{
			return last - first + 1;
		}
		else
		{
			return 0;
		}
	}
	//找第一个k的下标
	int getFirst(vector<int>& nums, int target, int left, int right)
	{
		if (left>right)//递归边界
		{
			return -1;
		}
		int mid = left + (right - left) / 2;
		if (nums[mid]==target)
		{
			if ((mid > 0 && nums[mid - 1] != target)||mid==0)
				//如果mid的下标在size-1内，并且它的前一个元素不等于target；
				//如果mid的下标为0，则一定为第一个k
			{
				return mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		else if(nums[mid]<target)//比目标值小向右边查找
		{
			left = mid + 1;

		}
		else //比目标值大向左边查找
		{
			right = mid - 1;
		}
		return getFirst(nums, target, left, right);//继续递归查找，直到left>right
	}
	int getLast(vector<int>& nums, int target, int left, int right)
	{
		if (left>right)//递归终止
		{
			return -1;
		}
		int mid = left + (right - left) / 2;
		if (nums[mid]==target)
		{
			if ((mid<nums.size()-1&&nums[mid+1]!=target)||mid==nums.size()-1)
			{
				return mid;
			}
			else
			{
				left = mid + 1;
			}
		}else if (nums[mid]<target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		return getLast(nums, target, left, right);
	}
};
```