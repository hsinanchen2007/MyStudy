### 解题思路
打家劫舍的环状版本，在这里将其拆分成两个部分的线性问题求解
### 代码

```c
#define MAX(a,b) (a>b?a:b)
int rob(int* nums, int numsSize) {
    if(!numsSize) return 0;
    if(numsSize==1) return nums[0];
	int rob0, rob1;
	int dp0, dp1;
	int temp0, temp1;
	dp0 = dp1 = 0;
	for (int i = 0; i < numsSize - 1; i++) {
		temp0 = MAX(dp0, dp1);
		temp1 = dp0 + nums[i];
		dp0 = temp0;
		dp1 = temp1;
	}
	rob0 = MAX(dp0, dp1);
	dp0 = dp1 = 0;
	for (int i = 1; i < numsSize; i++) {
		temp0 = MAX(dp0, dp1);
		temp1 = dp0 + nums[i];
		dp0 = temp0;
		dp1 = temp1;
	}
	rob1 = MAX(dp0,dp1);
	return MAX(rob0, rob1);
}
```