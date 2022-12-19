// https://blog.csdn.net/shinanhualiu/article/details/50550825

//dp[i] 代表能走到的最大索引值。

//dp[i] = max{ A[i] + i， dp[i-1] },   前提条件是: 上一步能走到的最大索引，包含了当前的索引，不然都走不到当前的索引，毫无意义。 即 dp[i-1] >= i



// 动态规划，自己写
#define MYMAX(x,y) ((x>y)?(x):(y))
bool canJump(int* nums, int numsSize) {
	bool canJumpFlag = false;
	if (numsSize == 1)//[0]
		return true;
	if (nums[0] == 0)
		return false;
	else {
		int *dp = (int *)malloc(sizeof(int) * numsSize); //分配一个数组，用于代表每一个索引出能往前走到的最大索引值。
		dp[0] = nums[0];

		for (int i = 1; i < (numsSize-1);i++) {
			if (dp[i - 1] >= i) {
				dp[i] = MYMAX(dp[i-1],nums[i]+i);
			} else {
				dp[i] = 0;
			}
		}

		if (dp[numsSize - 2] >= (numsSize - 1)) { //numsSize - 1代表倒数第一个元素， 代表能达到这个索引，则返回 true
			canJumpFlag = true;
		}
		free(dp);
		return canJumpFlag;
		
	}
}