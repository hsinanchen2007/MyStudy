class Solution {
public:
	int numRollsToTarget(int d, int f, int target) {
		int **dp;
		dp = new int*[d+1];
		for (int i = 0; i <=d; i++) {
			dp[i] = new int[target+f] {0};
		}
		dp[0][0] = 1;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j <=target; j++) {
				if (!dp[i][j])continue;
				for (int k = 1; k <=f; k++) {
					if (j + k <=target)
						(dp[i+1][j + k] += dp[i][j]) %= 1000000007;
				}
			}
		}
		int temp = dp[d][target];
	    delete []dp;
		return temp;
	}
};