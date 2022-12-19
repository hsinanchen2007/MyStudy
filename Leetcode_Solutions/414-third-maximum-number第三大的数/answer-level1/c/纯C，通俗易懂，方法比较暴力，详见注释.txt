### 解题思路
主要就是设好第一第二第三大的变量，然后遍历数组，逐次排出第一二三大。
判断是否有第三大只要看第二大和第三大是否一样。

### 代码

```c
int thirdMax(int* nums, int numsSize){
int min=nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		if (min > nums[i])
			min = nums[i];
	}//先把第一第二第三大的数都设为数组中最小的值，遇到比它大的再赋给相应的变量
	int max1 = min, max2 = min, max3 = min;
	for (int i = 0; i < numsSize; i++){
		if (nums[i] > max1){
			max3 = max2;
			max2 = max1;
			max1 = nums[i];//若元素比max1大，那么把最大的赋给第二大的，第二大的赋给第三大的，以此类推
		}
		else
			if (nums[i] > max2&& nums[i] < max1){
				max3 = max2;
				max2 = nums[i];//考虑比最大的小但是比第二大的大这种情况
			}
			else
				if (nums[i] > max3&& nums[i] < max2){
					max3 = nums[i];//考虑比第二大的小但是比第三大的大这种情况
				}
				else
					;
	}
	if (max3 == max2)//如果数组中不重复的元素不到三个，那么第二大和第三大一定是一样的
		return max1;
	else
		return max3;
}
```