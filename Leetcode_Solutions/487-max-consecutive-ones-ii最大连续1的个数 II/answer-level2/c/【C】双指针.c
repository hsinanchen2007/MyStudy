### 解题思路
最多将 1 个 0 翻转为 1，转化为改区间最多是一个0，然后进行滑窗，可以叫双指针

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxConsecutiveOnes(int* nums, int numsSize){
	int begin, end;
	int zeroCnt = 0;
	int ans = 0;

	begin = 0;
	/* 通常是让快指针先走，慢指针while直到满足条件 */
	for (end = 0; end < numsSize; end++) {
		if (nums[end] == 0) {
			zeroCnt++;
		}
		while (begin <= end && zeroCnt > 1) {
			if (nums[begin] == 0) {
				zeroCnt--;
			}
			begin++;
		}
		if (zeroCnt <= 1) {
			ans = MAX(ans, end - begin + 1);
		}
	}

	return ans;
}
```