### 解题思路
C# 递归回溯法

### 代码

```csharp
public class Solution {
    public bool Exist(char[][] board, string word) {
        for (int y = 0; y < board.Length; y++)
        {
            for (int x = 0; x < board[0].Length; x++)
            {
                if (Exist(board, x, y, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

    public bool Exist(char[][] board, int x, int y, string word, int wordIndex)
    {
        if (y < 0 || y >= board.Length || x < 0 || x >= board[0].Length) return false;

        var currentChar = word[wordIndex];
        if (board[y][x] != currentChar) return false;

        if (wordIndex == word.Length - 1) return true;
        
        // 避免重复回溯
        board[y][x] = '-';
        var result = Exist(board, x - 1, y, word, wordIndex + 1) ||
                        Exist(board, x + 1, y, word, wordIndex + 1) ||
                        Exist(board, x, y - 1, word, wordIndex + 1) ||
                        Exist(board, x, y + 1, word, wordIndex + 1);
        board[y][x] = currentChar;

        return result;
    }
}
```