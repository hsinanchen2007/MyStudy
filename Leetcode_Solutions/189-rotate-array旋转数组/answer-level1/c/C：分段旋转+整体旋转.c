思路：
按照k位置把数组分成两段后分别旋转，然后整体旋转就好
旋转这里用的是首尾交换到中间结束，交换用的是异或方法
```
void rotate(int* nums, int numsSize, int k){
	int i = 0, j = 0;
	k = k % numsSize;
	for (i = 0, j = numsSize - 1 - k; i<j; i++, j--){
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
	for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--){
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
	for (i = 0, j = numsSize-1; i<j; i++, j--){
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
}
```
