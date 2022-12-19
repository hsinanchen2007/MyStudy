### 解题思路
一台电脑，一支笔，一道算法做一天。

### 代码

```cpp
class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		int w, h;
		h = board.size();
		w = board[0].size();
		if ((h * w) < word.length())
		{
			return false;
		}
		for (int r = 0; r < board.size(); r++)
		{
			for (int c = 0; c < board[r].size(); c++)
			{
				if (board[r][c] == word[0])
				{
					string wo = word;
					if (searchFrom(r, c, board, wo, w, h))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

private:
	typedef struct Stacks
	{
		int row;
		int column;
		int num;
	} stack;
	int direct[4][2] = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0}};
	bool searchFrom(int &row, int &col, vector<vector<char>> &board, string world, int &w, int &h)
	{

		Stacks *s = new Stacks[w * h];
		Stacks *path = new Stacks[w * h];
		int pathTop = 0;
		vector<vector<bool>> map(h, vector<bool>(w, false));
		int top = 1;
		s[0].num = 0;
		s[0].row = row;
		s[0].column = col;

		int *p;
		int r, c, n, l;
		l = world.length();
		for (; top > 0;)
		{
			r = s[top - 1].row;
			c = s[top - 1].column;
			n = s[top - 1].num;
			map[r][c] = true;
			path[pathTop] = s[top - 1];
			pathTop++;
			if ((n + 1) == l)
			{
				return true;
			}
			top--;
			bool flag = true;
			for (int i = 0; i < 4; i++)
			{
				p = direct[i];
				if (r + p[0] >= 0 && c + p[1] >= 0 && c + p[1] < w && r + p[0] < h && board[r + p[0]][c + p[1]] == world[n + 1] && map[r + p[0]][c + p[1]] == false)
				{
					s[top].row = r + p[0];
					s[top].column = c + p[1];
					s[top].num = n + 1;
					top++;
					flag = false;
				}
			}
			if (flag)
			{
				int n;
				if (top - 1 == -1)
				{
					return false;
				}

				n = s[top - 1].num;
				while (true)
				{
					if (path[pathTop - 1].num == n)
					{
						map[path[pathTop - 1].row][path[pathTop - 1].column] = false;
						pathTop--;
						break;
					}
					map[path[pathTop - 1].row][path[pathTop - 1].column] = false;
					pathTop--;
				}
			}
		}
		return false;
	}
};
```