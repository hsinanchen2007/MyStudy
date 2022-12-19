### 解题思路
先找到R，然后再向四个方向找p

### 代码

```cpp
class Solution {
public:
	int onedirection(vector<vector<char>>& board, int i, int j, char dir) {//从(i，j）向dir这个方向出发，寻找p
		if (dir == 'u') {
			while (j > 0) {
				j--;
				if (board[i][j] == 'p') { return 1; }
				if (board[i][j] == 'B') { return 0; }
			}
			return 0;
		}
		if (dir == 'd') {
			while (j < 7) {
				j++;
				if (board[i][j] == 'p') { return 1; }
				if (board[i][j] == 'B') { return 0; }
			}
			return 0;
		}
		if (dir == 'l') {
			while (i > 0) {
				i--;
				if (board[i][j] == 'p') { return 1; }
				if (board[i][j] == 'B') { return 0; }
			}
			return 0;
		}
		if (dir == 'r') {
			while (i < 7) {
				i++;
				if (board[i][j] == 'p') { return 1; }
				if (board[i][j] == 'B') { return 0; }
			}
			return 0;
		}
		return -1;//因为要保证必须有一个return， 否则编译不能通过
	}
	int numRookCaptures(vector<vector<char>>& board) {
		int res = 0;
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (board[i][j] == 'R') {//寻找R
					res += onedirection(board, i, j, 'u');
					res += onedirection(board, i, j, 'd');
					res += onedirection(board, i, j, 'l');
					res += onedirection(board, i, j, 'r');
					return res;
				}
			}
		}
		return -1;//因为要保证必须有一个return， 否则编译不能通过
	}

};

```
