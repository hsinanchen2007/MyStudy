思想：
动态规划 得到前i-1个最大（由于i-1可以要或者不要，因此为Max）
 temp1得到前i个最大

### 代码

```c
#define MAX(a,b) (a>b?a:b)
int massage(int* nums, int numsSize) {
	if (!numsSize) return 0;
	int dp0 = 0;
	int dp1 = 0;
	int temp0, temp1;
	for (int i = 0; i < numsSize; i++) {
		temp0 = MAX(dp0, dp1);
		temp1 = dp0 + nums[i];
		dp0 = temp0;
		dp1 = temp1;
	}
	return MAX(dp0, dp1);
}

```