### 解题思路
遍历数组在nums[i]>=target时停止，此时i的位置为正确位置，如果没有正确位置，target插入numsSize位置。

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
	if(numsSize<1) {
		return 0;
	}
	
	for(int i=0; i<numsSize; i++) {
		if(nums[i]>=target) {
			return i;
		}
	}
	return numsSize;
}

```