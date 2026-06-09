### 解题思路

#### 思路一，创造一个临时的二维数组
创造一个和输入的数组大小一样的临时二维数组， 来储存更新后的值。待所有的值都更新之后，再将临时数组里面的值一个个赋值到原数组中。

#### 思路二，创造一个Dictionary
业务逻辑方面和思路一相同，共用同一个业务逻辑函数，但是本思路利用`Dictionary`来临时储存更新后的值，而非一个二维数组。

该`Dictionary`的Key是一个用来表示具体的坐标的Tuple，Item1是 row 的 index，Item2是 column 的 index。

### 代码

```csharp
public class Solution {
    public void GameOfLife(int[][] board)
    {
        GameOfLifeSecondTry(board);
    }

    public void GameOfLifeFirstTry(int[][] board)
    {
        // 执行用时: 408 ms, 在所有 C# 提交中击败了 16.67% 的用户
        // 内存消耗: 29.9 MB, 在所有 C# 提交中击败了 50.00% 的用户
        int[][] nextGenBoard = new int[board.Length][];

        for (int i = 0; i < board.Length; i++)
        {
            int[] boardRow = new int[board[i].Length];

            for (int j = 0; j < board[0].Length; j++)
            {
                boardRow[j] = UpdateCellStatus(board, i, j);
            }

            nextGenBoard[i] = boardRow;
        }

        for (int i = 0; i < board.Length; i++)
        {
            for (int j = 0; j < board[0].Length; j++)
            {
                board[i][j] = nextGenBoard[i][j];
            }
        }
    }

    public void GameOfLifeSecondTry(int[][] board)
    {
        // 执行用时: 280 ms, 在所有 C# 提交中击败了 83.33% 的用户
        // 内存消耗: 30.2 MB, 在所有 C# 提交中击败了 50.00% 的用户
        Dictionary<Tuple<int, int>, int> nextGenBoard = new Dictionary<Tuple<int, int>, int>();

        for (int i = 0; i < board.Length; i++)
        {
            for (int j = 0; j < board[0].Length; j++)
            {
                nextGenBoard[new Tuple<int, int>(i, j)] = UpdateCellStatus(board, i, j);
            }
        }

        for (int i = 0; i < board.Length; i++)
        {
            for (int j = 0; j < board[0].Length; j++)
            {
                board[i][j] = nextGenBoard[new Tuple<int, int>(i, j)];
            }
        }
    }

    public int UpdateCellStatus(int[][] board, int currentRowIndex, int currentColumnIndex) {
        int liveNeighborsCount = 0;

        int currentCellStatus = board[currentRowIndex][currentColumnIndex];

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) { continue; }

                int neighborRowIndex = currentRowIndex + i;
                int neighborColumnIndex = currentColumnIndex + j;

                if (neighborRowIndex < 0 || 
                    neighborRowIndex >= board.Length ||
                    neighborColumnIndex < 0 ||
                    neighborColumnIndex >= board[0].Length) {
                        continue;
                    }

                if (board[neighborRowIndex][neighborColumnIndex] == 1) {
                    liveNeighborsCount++;
                }
            }
        }

        if (currentCellStatus == 1) {
            if (liveNeighborsCount < 2) {
                // Rule 1
                return 0;
            } else if (liveNeighborsCount == 2 || liveNeighborsCount == 3) {
                // Rule 2
                return 1;
            } else if (liveNeighborsCount > 3) {
                // Rule 3
                return 0;
            }
        } else {
            if (liveNeighborsCount == 3) {
                // Rule 4
                return 1;
            }
        }

        return currentCellStatus;
    }
}
```