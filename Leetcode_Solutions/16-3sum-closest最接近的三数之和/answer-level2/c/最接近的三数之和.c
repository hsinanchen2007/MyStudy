### 解题思路
双指针法+去重处理
### 代码

```c
int cmp_int(const void * a, const void * b)
{
	return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
	//先进行排序
	qsort(nums, numsSize, sizeof(int), cmp_int);
	int res = nums[0] + nums[1] + nums[2];
	int sum = 0;
	for (int i = 0; i < numsSize-2 ; i++) {
		//固定一个值，移动另外两个指针
		int start = i + 1;
		int end = numsSize - 1;
		while (start < end) {
			sum = nums[i] + nums[start] + nums[end];
			if (abs(sum - target) < abs(res - target)) {
				res = sum;
			}
			if (sum < target) {
				start++;
				//解决元素重复问题
				while (start < end&&nums[start] == nums[start - 1])
					start++;
			}
			else if (sum > target) {
				end--;
				//解决元素重复问题
				while (start < end&&nums[end] == nums[end + 1])
					end--;
			}
			else {
				return res;
			}
		}
		while (i < numsSize - 2 && nums[i] == nums[i + 1])
			i++;
	}
	return res;
}
```