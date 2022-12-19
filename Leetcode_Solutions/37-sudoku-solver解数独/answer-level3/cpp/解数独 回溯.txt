其实是和N皇后很类似的回溯问题
从当前位置开始，依次探索放进当前数是否符合约束条件，若符合则填下一个数，不符合则回退

这里的条件用vecotr<vector<int>>rows,cols,blocks 来分别记录每一行、每一列、每一小方块是否出现了1-9中的数，出现则标1
其中九个小方格的索引可以用row/3*3+col/3来确定，整除

所以backtrack的部分是这样的：
```
vector<vector<int>>rows;
vector<vector<int>>cols;
vector<vector<int>>blocks;
bool fl;
void backtrack(int row, int col, vector<vector<char>>&board)
{
	if (row > 8)
	{
		fl = true;
		return;
	}
	if (board[row][col] != '.')
	{
		if (col == 8)
			backtrack(row + 1, 0, board);
		else
			backtrack(row, col + 1, board);
	}
	else {
		for (char k = '1'; k <= '9'; k++)
		{
            //已经出现过的数跳过
			if (rows[row][k - '0'] == 1)
				continue;
			if (cols[col][k - '0'] == 1)
				continue;
			if (blocks[row / 3 * 3 + col / 3][k-'0'] == 1)
				continue;

			board[row][col] = k;
			rows[row][k - '0'] = 1;
			cols[col][k - '0'] = 1;
			blocks[row / 3 * 3 + col / 3][k - '0'] = 1;


				if(col == 8)
					backtrack(row + 1, 0, board);
				else
					backtrack(row, col + 1, board);
				if (fl == true)
					return;
            //回退
				board[row][col] = '.';
				rows[row][k - '0'] = 0;
				cols[col][k - '0'] = 0;
				blocks[row / 3 * 3 + col / 3][k - '0'] = 0;
			
		}
	}
}
```
