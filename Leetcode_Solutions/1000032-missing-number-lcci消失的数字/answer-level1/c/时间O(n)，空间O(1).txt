### 解题思路
此处撰写解题思路

### 代码

```c
int missingNumber(int* nums, int numsSize){
	int s1 = numsSize, s2 = 0;
	for (int i = 0; i < numsSize; i++){
		s1 += i;
		s2 += nums[i];
	}
	return s1 - s2;
}
```