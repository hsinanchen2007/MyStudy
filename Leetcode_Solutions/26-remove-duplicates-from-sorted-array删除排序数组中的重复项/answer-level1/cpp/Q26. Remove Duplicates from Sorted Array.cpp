
简单的双指针题目。
解法一：快指针指向当前正遍历的元素，慢指针指向空出来的位置，如果当前数字和前一数字不相等，则将其赋值到慢指针。
```
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		vector<int>::size_type nSize = nums.size();
		if (nSize <= 1)
			return nSize;

		vector<int>::size_type p = 1;
		for (vector<int>::size_type i = 1; i < nSize; ++i) {
			if (nums[i] != nums[i - 1])
				nums[p++] = nums[i];
		}

		return p;
	}
};
```
解法二：快指针指向当前正遍历的元素，慢指针指向一个不同的数字，如果当前数字和慢指针所指数字不相等，则慢指针向后一位，并将该数字添加。
```
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		vector<int>::size_type nSize = nums.size();
		if (nSize <= 1)
			return nSize;

		vector<int>::size_type p = 0;
		for (vector<int>::size_type i = 1; i < nSize; ++i) {
			if (nums[i] != nums[p])
				nums[++p] = nums[i];
		}

		return p + 1;
	}
};
```
我果真不适合写题解，写文章啊！