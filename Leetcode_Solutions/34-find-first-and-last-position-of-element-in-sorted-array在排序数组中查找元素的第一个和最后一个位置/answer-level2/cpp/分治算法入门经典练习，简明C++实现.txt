### 解题思路
此处撰写解题思路
![34.png](https://pic.leetcode-cn.com/523c7f76a65373856cba5f97ac453b5ebf67c9858ec5dd31ca4b1edd0a36f85d-34.png)

本题是练习**分治算法**的经典练习题，使用**两遍二分查找**实现：
（1）**初始化**vector<int>res(2,-1)即初始化为两个-1；
（2）第一遍二分查找：找出目标索引**上界**，确定res[1];
（3）第二遍二分查找：找出目标索引**下界**, 确定res[0];
具体过程及注意事项详见代码注释部分！
### 代码

```cpp
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int>res(2, -1);    //初始化结果数组
	if (nums.size() == 0)
		return res;
	int L, i, j, pivot;       //L：数组大小 i：左指针 j：右指针 pivot：枢轴量
	L = nums.size();
	i = 0, j = L - 1;
	if (nums[i] > target || nums[j] < target)    //由于数组有序，直接输出结果的情况
		return res;
	while (i <= j) {   //第一遍二分查找确定目标索引上界
		pivot = i + (j - i) / 2;
		if (nums[pivot] == target) {
			if (pivot == L - 1 || nums[pivot + 1] > target)   //注意考虑边界情况以防数组越界
				res[1] = pivot;
		}
		if (nums[pivot] <= target)    //注意：此处不能是else if 否则陷入死循环！
			i = pivot + 1;
		else
			j = pivot - 1;
	}
	i = 0, j = L - 1;
	while (i <= j) {    //参照确定目标索引上届对称实现目标索引下界
		pivot = i + (j - i) / 2;
		if (nums[pivot] == target) {
			if (pivot == 0 || nums[pivot - 1] < target)
				res[0] = pivot;
		}
		if (nums[pivot] < target)     //注意：此处不能是else if 否则陷入死循环！
			i = pivot + 1;
		else
			j = pivot - 1;
	}
	return res;
}
};
```