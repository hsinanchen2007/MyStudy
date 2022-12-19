### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool IsValidSudoku(char[][] board) {
     	int[,] colStats = new int[10, 10];
			int[,] rowStats = new int[10, 10];
			int[,] boxStats = new int[10, 10];



			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (board[i][j] != '.')
					{
						var value = board[i][j] - '0';
						rowStats[j, value]++;
						colStats[i, value]++;
						int boxIndex = (i / 3) * 3 + j / 3;
						boxStats[boxIndex, value]++;
						if (rowStats[j, value] > 1 || colStats[i, value] > 1 || boxStats[boxIndex, value] > 1)
						{
							return false;
						}
					}
				}
			}

			return true;
    }
}
```