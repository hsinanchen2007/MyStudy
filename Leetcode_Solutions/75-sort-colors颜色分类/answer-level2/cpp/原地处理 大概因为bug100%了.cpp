根据提示，按照0,1,2的个数添加一个新的数组就可以
但是也可以不用额外的空间，用一个pre表示同样的数字连续到了哪个位置，三次O(n)的遍历，第一遍先找0，
pre从-1开始，如果当前数字是0，那么pre++，当前数字与pre处的数字交换，
保证pre总是当前数字的最后一个位置
然后从pre+1开始向后遍历找1，继而再找2
代码如下：
```
void sortColors(vector<int>& nums) {
		int pre = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0)
			{
				pre++;
				swap(nums[i], nums[pre]);
			}
		}
		
		for (int i = pre+1; i < nums.size(); i++) {
			if (nums[i] == 1) {
				pre++;
				swap(nums[i], nums[pre]);
			}
		}
		for (int i = pre + 1; i < nums.size(); i++) {
			if (nums[i] == 2)
			{
				pre++;
				swap(nums[i], nums[pre]);
			}
		}
	}
```
