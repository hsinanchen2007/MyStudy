根据题意直接模拟求解即可。
1. 先将`moves`转换成棋盘`grid`；
2. 然后检查是否有赢家(`checkWiner`)；如果有赢家则输出赢家；如果有没有赢家，则看`moves`步数是否填满了棋盘；如果填满了棋盘，则返回平局；否则返回游戏未结束。
```
class Solution {
public:
	string tictactoe(vector<vector<int>>& moves) {
		vector<vector<char>> grid(3, vector<char>(3, ' '));
		for (size_t i = 0; i < moves.size(); ++i) {
			grid[moves[i][0]][moves[i][1]] = ((i % 2 == 0) ? 'A' : 'B');
		}

		char cWiner = checkWiner(grid);
		if (cWiner != ' ')
			return string(1, cWiner);
		else if (moves.size() == grid.size() * grid[0].size())
			return string("Draw");
		else
			return string("Pending");
	}

	char checkWiner(const vector<vector<char>>& grid) {
		// 检查行
		for (size_t i = 0; i < grid.size(); ++i) {
			if (grid[i][0] == ' ')
				continue;

			size_t j = 1;
			while (j < grid[i].size() && grid[i][j] == grid[i][0])
				++j;

			if (j >= grid[i].size())
				return grid[i][0];
		}

		// 检查列
		for (size_t j = 0; j < grid[0].size(); ++j) {
			if (grid[0][j] == ' ')
				continue;

			size_t i = 1;
			while (i < grid.size() && grid[i][j] == grid[0][j])
				++i;

			if (i >= grid.size())
				return grid[0][j];
		}

		// 检查左上-右下对角线
		if (grid[0][0] != ' ') {
			size_t i = 1;
			while (i < grid.size() && grid[i][i] == grid[0][0])
				++i;

			if (i >= grid.size())
				return grid[0][0];
		}

		// 检查左下-右上对角线
		if (grid[grid.size() - 1][0] != ' ') {
			size_t i = 1;
			while (i < grid.size() && grid[grid.size() - i - 1][i] == grid[grid.size() - 1][0])
				++i;

			if (i >= grid.size())
				return grid[grid.size() - 1][0];
		}

		return ' ';
	}
};

```