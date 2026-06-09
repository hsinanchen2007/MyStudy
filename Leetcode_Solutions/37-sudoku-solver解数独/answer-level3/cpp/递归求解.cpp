### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
	const char B = '.';
	const char zero = '0';
	
public:
	using posnum = pair<int, int>;
	vector<posnum> buff;
	int ct;

	void solveSudoku(vector<vector<char>>& board) {
		init(board);
		solveLite(board);
	}
	void init(vector<vector<char>>& board) {
		buff.clear();
		ct = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != B) continue;
				ct++;
				buff.push_back(posnum(i, j));
			}
		}
	}
	bool solveLite(vector<vector<char>>& board) {
		//showBoard(board);
		if (buff.size() <= 0)
			return true;
		auto pos = buff.back();
		buff.pop_back();
		int i = pos.first;
		int j = pos.second;
		for (int k = 1; k <= 9; k++) {
			if (setBorad(board, i, j, k)){
				if (solveLite(board)) {
					return true;
				} else {
					board[i][j] = B;
				}
			}
		}
		buff.push_back(pos);
		return false;
	}

	bool setBorad(vector<vector<char>>& board, int i, int j, int k) {
		auto row = board[i];
		char n = zero + k;
		if (row.end() != find(row.begin(), row.end(), n)) return false;
		for (int w = 0; w < 9; w++) { if (board[w][j] == n) { return false; } }
		int ii = i / 3; ii *= 3;
		int jj = j / 3; jj *= 3;
		for (int a = ii; a < ii + 3; a++) {
			for (int b = jj; b < jj + 3; b++) {
				if (board[a][b] == n) { return false; } } }
		board[i][j] = n;
		return true;
	}

	void showBoard(vector<vector<char>>& board) {
		for (auto vc : board) {
			for (auto v : vc) {
				cout << v << " ";
			}
			cout << endl;
		}
		cout << "_________________" << endl;
	}

};
```