此题目太无聊了，直接上代码，就是找到白象，然后上下左右去找黑卒
```
int m = board.length;
		int n = board[0].length;
		int ni = -1;
		int nj = -1;
		for (int i = 0; i < m; i++)
		{
			boolean find = false;
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'R')
				{
					find = true;
					ni = i;
					nj = j;
					break;
				}
			}
		}
		int res = 0;
		for (int i = ni - 1; i >= 0; i--)
		{
			if (board[i][nj] == 'B')
			{
				break;
			}
			else if (board[i][nj] == 'p')
			{
				res++;
				break;
			}
		}
		for (int i = ni + 1; i < m; i++)
		{
			if (board[i][nj] == 'B')
			{
				break;
			}
			else if (board[i][nj] == 'p')
			{
				res++;
				break;
			}
		}

		for (int j = nj - 1; j >= 0; j--)
		{
			char c = board[ni][j];
			if (c == 'B')
			{
				break;
			}
			else if (c == 'p')
			{
				res++;
				break;
			}
		}
		for (int j = nj + 1; j < n; j++)
		{
			char c = board[ni][j];
			if (c == 'B')
			{
				break;
			}
			else if (c == 'p')
			{
				res++;
				break;
			}
		}
		return res;
```
