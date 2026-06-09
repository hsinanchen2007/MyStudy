
```
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0;
		int end = nums.size() - 1;
		if (begin<=end)//否则为空，返回-1
			return refind(nums, begin, end, target);
		return -1;
	}
private:
	int refind(vector<int>& nums,int begin,int end,int target)
	{
		int mid = (begin + end) / 2;
		if (nums[mid]==target)
			return mid;
		//数组一分为二，target在有序部分则调二分查，target在部分有序则调递归
		//前有序 且 在前
		else if (nums[begin]<=target && target<nums[mid])
			return find_target(nums, begin, mid - 1, target);

		//后无序 且 不在前
		else if (nums[end] < nums[mid])
			return refind(nums, mid + 1, end, target);

		//后有序 且 在后
		else if (nums[mid]<target && target <= nums[end])
			return find_target(nums, mid + 1, end, target);

		//前无序 且 不在后
		else if (nums[begin]>nums[mid])
			return refind(nums, begin, mid - 1, target);

		return -1;
	}

	//二分法找target的位置
	int find_target(vector<int>& nums,int begin,int end,int target)
	{
		while (begin<=end)
		{
			int mid = (end + begin) / 2;
			if (target == nums[mid])
				return mid;
			else if (target > nums[mid])
			{
				if (mid == nums.size() - 1 || target < nums[mid + 1])
					return -1;
				begin = mid + 1;//注意这里
			}
			else if (target<nums[mid])
			{
				if (mid == 0 || target>nums[mid - 1])
					return -1;
				end = mid - 1;//注意这里
			}
		}
		return -1;
	}
};
```
