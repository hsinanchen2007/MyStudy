就是回溯法，但是事先维护3个“判据”：行判据、列判据、九宫格判据，判据用了位运算进行比较，可节省一些内存空间

每次遇到“.”的时候，就试一次0~9的数字，要是跟判据没有冲突，那就继续回溯，有冲突就试下一个数字

其实最烦人的就是char跟int转来转去。。。

```
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		this->initCriteria(board);
		this->fill(board, 0, 0);
	}

private:
	vector<int> rowCriteria, colCriteria, cellCriteria;
	int size = 9, cellSize = 3;
	bool finish = false;

	void initCriteria(vector<vector<char>>& board)
	{
		int cellNum;
		char numChar;

		this->rowCriteria = vector<int>(this->size, 0);
		this->colCriteria = vector<int>(this->size, 0);
		this->cellCriteria = vector<int>(this->size, 0);

		for (int x = 0; x < this->size; x++)
		{
			for (int y = 0; y < this->size; y++)
			{
				if (board[x][y] != '.')
				{
					numChar = (int)board[x][y] - int('0');
					this->criteriaAdd(x, y, 1 << numChar);
				}
			}
		}
	}

	void fill(vector<vector<char>>& board, int x, int y)
	{
		int tmp, cellNum;

		while (x < this->size)
		{
			while (y < this->size)
			{
				if (board[x][y] == '.')
				{
					for (int i = 1; i <= this->size; i++)
					{
						tmp = 1 << i;
						cellNum = x / this->cellSize * this->cellSize + y / this->cellSize;
						if ((this->rowCriteria[x] & tmp) == 0 &&
							(this->colCriteria[y] & tmp) == 0 &&
							(this->cellCriteria[cellNum] & tmp) == 0)
						{
							board[x][y] = char('0' + i);
							this->criteriaAdd(x, y, tmp);
							this->fill(board, x, y + 1);
							if (this->finish)
							{
								return;
							}
							else
							{
								this->criteriaAdd(x, y, tmp, false);
							}
						}
					}
					board[x][y] = '.';
					return;
				}
				y++;
			}
			y = 0;
			x++;
		}
		this->finish = true;
	}

	void criteriaAdd(int x, int y, int num, bool add = true)
	{
		int cellNum;

		this->rowCriteria[x] = add ? this->rowCriteria[x] + num : this->rowCriteria[x] - num;
		this->colCriteria[y] = add ? this->colCriteria[y] + num : this->colCriteria[y] - num;

		cellNum = x / this->cellSize * this->cellSize + y / this->cellSize;
		this->cellCriteria[cellNum] = add ? this->cellCriteria[cellNum] + num : this->cellCriteria[cellNum] - num;
	}
};
```
