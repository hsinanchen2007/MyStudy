```
class Solution {
public:
	vector<int> pathsWithMaxScore(vector<string>& board) {
		const int ModNum = 1000000007;
		size_t n = board.size();
		size_t m = board[0].size();
		board[0][0] = board[n - 1][m - 1] = '0';

		// 表示到达(i,j)位置能得到的最大得分
		vector<vector<int>> dpMaxSum(n + 1, vector<int>(m + 1, 0));
		// 表示以最大得分到达(i,j)位置的路径数目
		vector<vector<int>> dpPathsNum(n + 1, vector<int>(m + 1, 0));

		// 初始状态
		dpPathsNum[n - 1][m - 1] = 1;

		// 递推
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = m - 1; j >= 0; --j)
			{
				if (board[i][j] != 'X' && (dpPathsNum[i + 1][j] || dpPathsNum[i][j + 1] || dpPathsNum[i + 1][j + 1]))
				{
					int nMaxScore = max(max(dpMaxSum[i + 1][j], dpMaxSum[i][j + 1]), dpMaxSum[i + 1][j + 1]);
					dpMaxSum[i][j] = nMaxScore + board[i][j] - '0';

					if (dpMaxSum[i + 1][j] == nMaxScore)
						dpPathsNum[i][j] = (dpPathsNum[i][j] + dpPathsNum[i + 1][j]) % ModNum;
					if (dpMaxSum[i][j + 1] == nMaxScore)
						dpPathsNum[i][j] = (dpPathsNum[i][j] + dpPathsNum[i][j + 1]) % ModNum;
					if (dpMaxSum[i + 1][j + 1] == nMaxScore)
						dpPathsNum[i][j] = (dpPathsNum[i][j] + dpPathsNum[i + 1][j + 1]) % ModNum;
				}
			}
		}

		vector<int> ans;
		ans.push_back(dpMaxSum[0][0]);
		ans.push_back(dpPathsNum[0][0]);
		return ans;
	}
};
```