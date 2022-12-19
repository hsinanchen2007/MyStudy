我觉得这道题的关键是保证了所有的输入都是合法的。这样才保证了问题有一次扫描，常数空间开销的解。
解法就是：当当前点是‘X’时，如果“上一个”或者“左边一个”也是‘X’时什么都不做，否则当前点就增加1。
这样做的思路就是找到战舰的“开始位置”

```
class Solution 
{
public:
	int countBattleships(vector<vector<char>>& board) 
	{
		int cnt = 0;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (board[i][j] == 'X')
				{
					if ((i - 1 >= 0 && board[i - 1][j] == 'X') || (j - 1 >= 0 && board[i][j - 1] == 'X'))
					{
					}
					else
					{
						++cnt;
					}
				}
			}
		}

		return cnt;
	}
};
```
