### 解题思路
因为题目固定了是9*9的格子，所以横与竖的检测可以放置在一起。

### 代码

```csharp
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        int[] statsCountRow = new int[10];
			int[] statsCountCol = new int[10];
			int[] statsCountRect = new int[10];


			int row = board.Length;
			int col = board[0].Length;

			for (int i = 0; i < row; i++)
			{
				ResetStats (statsCountCol);
				ResetStats (statsCountRow);
				for (int j = 0; j < col; j++)
				{
					var tarRow = board[i][j] - '0';
					var tarCol = board[j][i] - '0';

					if (tarRow <= 9&&tarRow>0)
					{
						statsCountRow[tarRow]++;
						if (statsCountRow[tarRow] > 1)
						{
							return false;
						}
					}

					if (tarCol <= 9&&tarCol>0)
					{
						statsCountCol[tarCol]++;
						if (statsCountCol[tarCol] > 1)
						{
							return false;
						}
					}
				}
			}




			for (int rowStart = 0; rowStart < 9; rowStart += 3)
			{
				for (int colStart = 0; colStart < 9; colStart += 3)
				{
                    ResetStats (statsCountRect);
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							var tar = board[i + rowStart][j + colStart] - '0';

							if (tar <= 9&&tar>0)
							{
								statsCountRect[tar]++;
								if (statsCountRect[tar] > 1)
								{
									return false;
								}
							}
						}
					}
				}
			}


			return true;
    }

    	void ResetStats (int[] stats)
		{
			for (int i = 0; i < stats.Length; i++)
			{
				stats[i] = 0;
			}
		}
}
```