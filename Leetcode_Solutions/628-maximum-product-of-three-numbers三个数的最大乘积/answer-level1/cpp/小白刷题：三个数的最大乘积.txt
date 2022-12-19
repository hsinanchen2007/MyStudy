无论数组元素是正是负，最大值必然在最大三个数的乘积，与最小两个数和最大数的乘积中产生

因此把这五个数找出来，乘积比较即可。需要的只是这五个数，而不是整体顺序，因此不需要排序，遍历找出即可

代码：
```
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int max1, max2, max3, min1, min2;
		max1 = min1 = 0;
		int len = nums.size();
		for (int i = 1; i < len; i++) {
			if (nums[i] > nums[max1])
				max1 = i;
			if (nums[i] < nums[min1])
				min1 = i;
		}
		max2 = max1 ? 0 : 1;
		min2 = min1 ? 0 : 1;
		for (int i = 1; i < len; i++) {
			if (nums[i] > nums[max2] && i != max1)
				max2 = i;
			if (nums[i] < nums[min2] && i != min1)
				min2 = i;
		}
		if (max1 == 0 || max2 == 0) {
			if (max1 == 1 || max2 == 1) {
				max3 = 2;
			}
			else
				max3 = 1;
		}
		else
			max3 = 0;
		for (int i = max3; i < len; i++) {
			if (nums[i] > nums[max3] && i != max1 && i != max2)
				max3 = i;
		}
		int ans1 = nums[min1] * nums[min2] * nums[max1];
		int ans2 = nums[max3] * nums[max2] * nums[max1];
		return ans1 > ans2 ? ans1 : ans2;
	}
};
```
