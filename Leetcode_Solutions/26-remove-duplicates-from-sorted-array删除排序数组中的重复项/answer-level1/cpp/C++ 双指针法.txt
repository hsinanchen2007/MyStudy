### 解题思路
双指针法
i为慢指针，j为快指针
但nums[j]==nums[j-1]时，直接跳过，如果不相等，则复制nums[j]给nums[i]，并同时递增两个索引，重复这一过程，直到j到达数组的末尾，该数组的新长度为i

### 代码

```cpp
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 1) return 0;
		int i = 1;//慢指针
		for (int j=1;j<nums.size();j++)
		{
			if (nums[j]!=nums[j-1])
			{
				nums[i++] = nums[j];
			}
		}
		return i;
	}
};
```