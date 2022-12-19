### 解题思路
双指针，就地交换

### 代码

```c
void moveZeroes(int* nums, int numsSize){
	int l, r;
	int tmp;
	if (nums == NULL || numsSize <= 1) {
		return;
	}
	l = 0;
	r = 1;
	while(r < numsSize) {
		while(l < numsSize && nums[l] != 0) {
			l++;
			r++;
		}
		while(r < numsSize && nums[r] == 0) {
			r++;
		}
		if (r >= numsSize) {
			continue;
		}
		tmp = nums[l];
		nums[l] = nums[r];
		nums[r] = tmp;
	}
	return;
}
```