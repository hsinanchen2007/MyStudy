### 解题思路
从离终点最近的位置开始，每次试图通过最少的条数到达终点，如果直接跳到，记录跳数是1，如果不能，试图跳到能到达的需要最少跳数的点上，跳数记为该点跳数加1，如果可达点内没有点可达，则记为-1不可达，last用于加快速度

### 代码

```c
int jump(int* nums, int numsSize) {
	int* jump_min = (int*)malloc(sizeof(int)*numsSize);
	int min = -1; 
	int last = numsSize - 1;
	jump_min[numsSize - 1] = 0;
	int res = -1;
	for (int i = numsSize-2; i >= 0; i--) {
		if ((nums[i] + i) >= (numsSize - 1)) {
			jump_min[i] = 1;
			last = i;
		}else if (last > (nums[i] + i)) {
			jump_min[i] = -1;
		}
		else {
			min = jump_min[last];
			for (int j = last; j <= nums[i] + i; j++) {
				if (jump_min[j] < min&&jump_min[j] >= 0) min = jump_min[j];
			}
			jump_min[i] = min + 1;
			last = i;
		}	
	}
	res = jump_min[0];
	free(jump_min);
	return res;
}
```