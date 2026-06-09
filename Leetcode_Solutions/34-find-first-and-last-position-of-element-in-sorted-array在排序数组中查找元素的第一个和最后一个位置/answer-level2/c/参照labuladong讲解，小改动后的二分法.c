1）初始变量为left = 0, **right = numsSize - 1**
2）循环条件为while (left **<=** right) 即搜索范围为[left, right]
3）退出循环后，需要判断返回的left或者right是否合法。判断条件为**left == numsSize**和**right == -1**
4）当left或者right合法时，给出target的存在范围。按照(left + right) / 2中的除法是取下界，所以只有在搜索到仅剩一个数的时候，mid = (left + right) / 2 = (right + right) / 2，无论进入ifelse的哪一个分支，都会使得left > right
而这最后一个数就是决定taget是否在数组中存在的最后希望。
因此，需要
```
return nums[left] == target ? left : -1;
```
进行判断。

完整代码如下
```

int left_bound(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			right = mid - 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	
	if (left == numsSize) return -1;
	return nums[left] == target ? left : -1; 	
}

int right_bound(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;
	
	while (left <= right) {
		int mid= (left + right) / 2;
		if (nums[mid] == target) 
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	
	if (right == -1) return -1;
	return nums[right] == target ? right : -1;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	*returnSize = 2;
	int *ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = left_bound(nums, numsSize, target);
	ret[1] =  right_bound(nums, numsSize, target);
	return ret;
}
```
