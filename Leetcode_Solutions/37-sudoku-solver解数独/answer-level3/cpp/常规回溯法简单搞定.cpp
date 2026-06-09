### 解题思路
因为此问题假设只有1解
问题分为
1.判断9x9方格是否填满，若填满直接返回，若未填满则下一步
2.计算每一次可以填的数字，若数字个数>0则进行递归调用，若数字个数<0则回溯
3.回溯将当前的位置置为空，并且将当前数字出栈

### 代码

```cpp
class Solution {
public:

	void print(std::vector<std::vector<char>>& board) {
		std::cout << std::endl;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				std::cout << board[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	bool isEmpty(std::vector<std::vector<char>>& board) {
		bool re = false;
		for (int k = 0; k < 9; k++) {
			for (int f = 0; f < 9; f++) {
				if (board[k][f] == '.') {
					re = true; return re;
				}
			}
		}
		return re;
	}
	void calFreeNum(int& i, int& j, std::vector<std::vector<char>>& board, std::vector<char>& dir) {
		for (int k = 0; k < 9; k++) {
			for (int f = 0; f < 9; f++) {
				if (board[k][f] == '.') {
					i = k; j = f;
					goto NextStep;
				}
			}
		}
		//计算当前位置可以放置的元素
	NextStep:
		for (int k = 0; k < 9; k++) {
			if (board[i][k] != '.')
				dir[board[i][k] - '1'] = '0';
			if (board[k][j] != '.')
				dir[board[k][j] - '1'] = '0';
		}

		int spanX = i / 3, spanY = j / 3;
		for (int k = spanX * 3; k < 3 * (spanX + 1); k++) {
			for (int f = spanY * 3; f < 3 * (spanY + 1); f++) {
				if (board[k][f] != '.')
					dir[board[k][f] - '1'] = '0';
			}
		}
		for (int p = 0; p < dir.size(); p++) {
			if (dir[p] == '0') {
				std::vector<char>::iterator it = dir.begin() + p;
				dir.erase(it);
				p--;
			}
		}
	}
	void backTrack(int i, int j, std::vector<std::vector<char>>& board, std::vector<char> dir) {
		//查找空位置
		if (!isEmpty(board)) {
			res = board;
			isStraightBack = true;
			return ;
		}
		if (j == 9) {
			i++;
			j = 0;
			backTrack(i, j, board, dir);
		}
		//计算还有多少数字可以用
		calFreeNum(i, j, board, dir);
		while (dir.size() > 0) {
			
			board[i][j] = dir.back();
			
			std::vector<char> temp = { '1','2','3','4','5','6','7','8','9' };
			backTrack(i, j + 1, board, temp);
			//回溯
			board[i][j] = '.';
			if (isStraightBack)dir.clear();
			else dir.pop_back();
		}
		
	}
	void solveSudoku(std::vector<std::vector<char>>& board) {
		std::vector<char> dir = { '1','2','3','4','5','6','7','8','9' };
		backTrack(0, 0, board, dir);
		board = res;
	}
private:
	std::vector<std::vector<char>> res;
	bool isStraightBack = false;
};
```