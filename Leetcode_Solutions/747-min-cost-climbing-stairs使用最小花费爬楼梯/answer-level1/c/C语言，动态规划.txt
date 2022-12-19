
执行用时 :4 ms, 在所有 C 提交中击败了98.18%的用户
内存消耗 :5.7 MB, 在所有 C 提交中击败了100.00%的用户
思路比较简单，到达当前这一步的步数等于倒数第二步和倒数第一步中取小的结果 
#define MIN(a,b) (a) < (b) ? (a) : (b) 
int minCostClimbingStairs(int* cost, int costSize) {
	int* dp = malloc(sizeof(int) * (costSize + 1));
	int i;
	dp[0] = 0;
	dp[1] = 0;
	for (i = 2; i < (costSize + 1); i++) {
		dp[i] = MIN(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
	}
	return dp[costSize];
}