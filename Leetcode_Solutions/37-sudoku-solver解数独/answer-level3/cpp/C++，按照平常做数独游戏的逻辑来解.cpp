![image.png](https://pic.leetcode-cn.com/101451af0b510fe58520f509e998ed788b6177629024ddc7503991906ce7a234-image.png)

```
class Solution {
	bool solveSudoku(vector<vector<char>>& board, bool perRow[9][9],
		bool perCol[9][9], bool perCell[9][9]) {
		//寻找可填数字最少的空格
		int r = -1, c = -1, minavail = 10;
		for (int i = 0;i < 9;++i) {
			for (int j = 0;j < 9;++j) {
				if (board[i][j] == '.') {
					int curavail = 0;
					for (int n = 0;n < 9;++n) {
						if (perRow[i][n] == false && perCol[j][n] == false &&
							perCell[i / 3 * 3 + j / 3][n] == false) ++curavail;
					}
					if (curavail == 0)return false;//存在无法填的格子，直接返回
					else if (curavail < minavail) {
						minavail = curavail;
						r = i;
						c = j;
					}
				}
			}
		}
		if (minavail == 10)return true;//minavail没被动过，说明填完了

		bool available[9];
		memset(available, 1, sizeof(available));//初始化为true
		int cellIdx = r / 3 * 3 + c / 3;
		//查找当前格子里能填的数字
		for (int i = 0;i < 9;++i) {
			if (perRow[r][i] == true || perCol[c][i] == true ||
				perCell[cellIdx][i] == true)available[i] = false;
		}
		for (int i = 0;i < 9;++i) {
			if (available[i]) {
				board[r][c] = '1' + i;
				perRow[r][i] = perCol[c][i] = perCell[cellIdx][i] = true;
				if (solveSudoku(board, perRow, perCol, perCell))
					return true;
				perRow[r][i] = perCol[c][i] = perCell[cellIdx][i] = false;
				board[r][c] = '.';
			}
		}
		return false;
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		bool perRow[9][9] = { false };
		bool perCol[9][9] = { false };
		bool perCell[9][9] = { false };
		//初始化
		for (int i = 0;i < 9;++i) {
			for (int j = 0;j < 9;++j) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '1';
					perRow[i][num] = true;
					perCol[j][num] = true;
					perCell[i / 3 * 3 + j / 3][num] = true;
				}
			}
		}
		solveSudoku(board, perRow, perCol, perCell);
	}
};
```
