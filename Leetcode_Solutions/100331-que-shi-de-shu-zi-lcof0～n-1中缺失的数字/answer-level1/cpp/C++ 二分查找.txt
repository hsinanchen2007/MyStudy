### 解题思路
1、如果mid和该数相等，则说明不相等的数在右侧，向右边找
2、如果mid和该数不相等，则分两种情况判断
- 如果mid==0,说明位于数组的第一个元素，则说明缺少的就是mid；如果前一个元素和其下标相等，说明mid为第一个不相等的数
- 如果没有满足上两种情况，说明第一个不相等的数在左侧，继续往左找
3、继续递归查找，如果发现left>right，说明没有找到的这个数，就是第n个数

### 代码

```cpp
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		return getMissIndex(nums, 0, nums.size()-1);
	}
	int getMissIndex(vector<int>& nums, int left, int right)
	{
		if (left > right) return nums.size();//如果最后都没有找到，说明缺少的就是n
		int mid = left + (right - left) / 2;
		if (nums[mid]==mid)//该数相等，说明第一个不相等的数在右侧，往右找
		{
			left = mid + 1;
		}
		else
		{
			if (mid==0||nums[mid-1]==mid-1)
				//mid==0时，且mid!=mid则直接返回
				//前一个相等，则说明该mid为第一个不相等的数
			{
				return mid;
			}
			else //不满足上述条件，说明第一个不相等的数在左侧，往左找
			{
				right = mid - 1;
			}
		}
		return getMissIndex(nums, left, right);
	}
};
```