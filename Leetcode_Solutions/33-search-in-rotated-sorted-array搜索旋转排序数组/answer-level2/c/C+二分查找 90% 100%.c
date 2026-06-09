### 解题思路
此题做法和官方给出的差不多，但是在寻找最小数那部分，此解法用的方法[https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/]为153题的官方解法
![捕获.JPG](https://pic.leetcode-cn.com/df701d6f8b0019905bb0d1931c9fb44a2d96937ad81736970eac2ddc55532122-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```c
/*
解法同官方过程的思想类似，用两遍二分，第一遍寻找出最小值的位置（flag）；
第二遍来进行二分查找；
找最小值位置的目的是：最小值左边（若不是第0位）为最大值，看target是否在nums[0]和nums[flag-1]间，若是，则在0~flag-1区间二分查找，否则在flag~numsSize-1区间查找；（这个过程都是基于flag不在0的基础上的）
*/
int search(int* nums, int numsSize, int target) {
	if (numsSize == 0 || numsSize == 1 && nums[0] != target)
		return -1;
/*
flag为最小值的位置
t的作用为标志是否旋转数组（即判断flag是否为0），如果没有旋转（为0）那可以跳过寻找最小数阶段

*/
	int left = 0, right = numsSize - 1, mid, flag = 0, t = 1;
	if (nums[0] < nums[numsSize - 1])
		t = 0;
	while (left <= right && t) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else {
			if (nums[mid] > nums[mid + 1]) {
				flag = mid + 1;
				break;
			}
			if (nums[mid-1] > nums[mid]) {
				flag = mid;
				break;
			}

			if (nums[mid] > nums[0])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
/*
接下来是第二遍二分，要重新判断left和right
*/
	if (flag == 0) { //最小值就是第0位
		left = 0;
		right = numsSize - 1;
	}
	else if (flag == numsSize - 1) { //最小值是最后一位
		if (nums[flag] == target)
			return flag;
		else {
			left = 0;
			right = flag - 1;
		}

	}
	else { //其他情况
		if (target >= nums[0] && target <= nums[flag - 1]) {
			left = 0;
			right = flag - 1;
		}
		else {
			left = flag;
			right = numsSize - 1;
		}
	}
//进行二分查找
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
	

}

```