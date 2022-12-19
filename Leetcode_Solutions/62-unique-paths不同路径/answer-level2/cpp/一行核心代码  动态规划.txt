class Solution {
public:
	int uniquePaths(int m, int n) {

		vector<vector<int>> memo = vector<vector<int>>(m, vector<int>(n, 1));

		for (int row = m - 2; row >= 0; row--) 
			for (int col = n - 2; col >= 0; col--) 
				memo[row][col] = memo[row + 1][col] + memo[row][col + 1];

		return memo[0][0];
	}
};