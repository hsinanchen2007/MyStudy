![image.png](https://pic.leetcode-cn.com/93c79019cff8e80d883fb31ffa94004ad8c13ceee6e744e26813cd8baeae8265-image.png)
时间复杂度O(mn)
添加首行首列、末行末列为0值。只需判断八个位置之和即可。
[0, 0, 0, 0, 0]
[0, **0, 1, 0**, 0]
[0, **0, 0, 1**, 0]
[0, **1, 1, 1**, 0]
[0, **0, 0, 0**, 0]
[0, 0, 0, 0, 0]

```
    public void gameOfLife(int[][] board) {
        int sum = 0;

        int[][] boardTmp = new int[board.length + 2][board[0].length + 2];

        for (int i = 0; i < boardTmp.length - 2; i++) {
            for (int j = 0; j < boardTmp[0].length - 2; j++) {
                boardTmp[i + 1][j + 1] = board[i][j];
            }
        }

        for (int i = 0; i < boardTmp.length - 2; i++) {
            for (int j = 0; j < boardTmp[0].length - 2; j++) {
                sum += boardTmp[i][j] + boardTmp[i][j + 1] + boardTmp[i][j + 2] + boardTmp[i + 1][j]
                        + boardTmp[i + 1][j + 2] + boardTmp[i + 2][j] + boardTmp[i + 2][j + 1] + boardTmp[i + 2][j + 2];
                int n = boardTmp[i + 1][j + 1];
                if (n == 1) {
                    if (sum < 2 || sum > 3) {
                        board[i][j] = 0;
                    }
                }
                if (n == 0) {
                    if (sum == 3) {
                        board[i][j] = 1;
                    }
                }
                sum = 0;
            }
        }
    }
```
