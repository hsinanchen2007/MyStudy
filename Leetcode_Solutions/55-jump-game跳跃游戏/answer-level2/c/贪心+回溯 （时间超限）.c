```


bool walk(int* nums, int numsSize, int step) {
	int jump;
	int i;
	
	if (step >= numsSize - 1) {
		return true;
	}
	
	if (nums[step] == 0) {
		return false;
	}
	
	// 贪心+回溯 
	jump = nums[step];
	for (i = 1; i <= jump; i++) {
		if (walk(nums, numsSize, step + i) == true) {
			return true;
		}
	}
	return false;
}


bool canJump(int* nums, int numsSize){
	return walk(nums, numsSize, 0);
}

```
