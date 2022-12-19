### 解题思路
此处撰写解题思路

### 代码

```csharp

	public class Solution
	{
		char[] target;
		char[][] container;
		int row;
		int col;
		int[][] map;

		public bool Exist (char[][] board, string word)
		{
			container = board;
			target = word.ToCharArray ();
			row = board.Length;
			col = board[0].Length;

			if (target.Length> col*row)
			{
				return false;
			}


			//construct map
			map = new int[row][];
			for (int i = 0; i < row; i++)
			{
				map[i] = new int[col];
				for (int j = 0; j < col; j++)
				{
					map[i][j] = 0;
				}
			}

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (target[0] == board[i][j])
					{
						if(FindNext (i, j, 1))
						{
							return true;
						}
						
					}
				}
			}
			return false;

		}


		bool FindNext (int rowIndex, int colIndex, int tarCharIndex)
		{
			map[rowIndex][colIndex] = 1;

			if (tarCharIndex == target.Length)
			{
				return true;
			}
			int colAdd = colIndex + 1;
			int colMinus = colIndex - 1;
			int rowIndexAdd = rowIndex + 1;
			int rowIndexMinus = rowIndex - 1;
			int nextTar = tarCharIndex + 1;

			///left 0 right 1 up 2 down 3
			if (colAdd < col && map[rowIndex][colAdd] != 1)
			{
				if (container[rowIndex][colAdd] == target[tarCharIndex])
				{
					if (FindNext (rowIndex, colAdd, nextTar)) { return true; }
				}

			}
			if (colMinus >= 0 && map[rowIndex][colMinus] != 1)
			{
				if (container[rowIndex][colMinus] == target[tarCharIndex])
				{
					if (FindNext (rowIndex, colMinus, nextTar)) { return true; }
				}
			}
			if (rowIndexAdd < row && map[rowIndexAdd][colIndex] != 1)
			{
				if (container[rowIndexAdd][colIndex] == target[tarCharIndex])
				{
					if (FindNext (rowIndexAdd, colIndex, nextTar)) { return true; }
				}
			}

			if (rowIndexMinus >= 0 && map[rowIndexMinus][colIndex] != 1)
			{
				if (container[rowIndexMinus][colIndex] == target[tarCharIndex])
				{
					if (FindNext (rowIndexMinus, colIndex, nextTar)) { return true; }
				}
			}
			map[rowIndex][colIndex] = 0;
			return false;
		}



	}


```

其实我一开始是这么写的
```
bool result;
void FindNext()
{
	if(...){
		result = true;
		return;
	}

}

```
可是这样会导致一个问题，就是即使找到了答案，也不会立即返回，而是继续搜寻。