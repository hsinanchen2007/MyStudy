### 解题思路
LeetCode官方解法
双指针，但nums[j]与给定的值相等时，递增j以跳过该元素。只要nums[j]!=val，就赋值nums[j]到nums[i]并同时递增两个索引。重复这一过程，直到j到达数组的末尾，该数组的新长度为i

### 代码

```cpp
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		//i为慢指针,j为快指针
		int i = 0;
		for (int j=0;j<nums.size();j++)
		{
			if (nums[j]!=val)
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};
```