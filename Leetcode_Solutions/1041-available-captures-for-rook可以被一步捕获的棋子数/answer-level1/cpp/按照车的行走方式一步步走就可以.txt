分别按四个方向判断是否能吃到兵。
每个方向最多吃到一个兵，而且如果吃到肯定是最先碰到的兵，碰到兵之前有资方象挡着肯定就吃不到兵了。
所以每个方向按题意一步步走，若先遇到象则结束该方向搜索，若遇到兵则吃掉并结束该方向搜索。

```C++ []
class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int res = 0;
		int n, m;
		bool stop = false;
		for (n = 0; n < 8; n++) {
			for (m = 0; m < 8; m++) {
				if (board[n][m] == 'R') {
					stop = true;
					break;
				}
			}
			if (stop)
				break;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (board[i][m] == 'p') {
				res++;
				break;
			}
			if (board[i][m] == 'B')
				break;
		}
		for (int i = n + 1; i < 8; i++) {
			if (board[i][m] == 'p') {
				res++;
				break;
			}
			if (board[i][m] == 'B')
				break;
		}
		for (int j = m - 1; j >= 0; j--) {
			if (board[n][j] == 'p') {
				res++;
				break;
			}
			if (board[n][j] == 'B')
				break;
		}
		for (int j = m + 1; j < 8; j++) {
			if (board[n][j] == 'p') {
				res++;
				break;
			}
			if (board[n][j] == 'B')
				break;
		}
		return res;
	}
};
```
