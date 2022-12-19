#### 回溯算法其实是一个套路题，只要熟悉代码模板并形成肌肉记忆，套代码模板即可

```
result = []
def backtrack(路径, 选择列表。。。):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表。。。)
        撤销选择

PS：回溯本质上是递归，模板套进去之后，下一步主要是找准 【方法参数】 和 【递归出口条件】
```

#### 题解

```
    public boolean exist(char[][] board, String word) {
        if (word == null || word.length() == 0 ||
                board.length == 0 || board[0].length == 0) {
            return false;
        }

        int row = board.length, column = board[0].length;
        boolean[][] visited = new boolean[row][column];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                // 找到其实位置（可能有多个）
                if (board[i][j] == word.charAt(0)) {
                    if (backtrack(0, i, j, board, word, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public boolean backtrack(int index, int i, int j, char[][] board, String word, boolean[][] visited) {
        int row = board.length;
        int column = board[0].length;
        // 超出二维网格，直接返回false
        if (i < 0 || j < 0 || i > row - 1 || j > column - 1) {
            return false;
        }

        // 重复使用，直接返回false
        if (visited[i][j]) {
            return false;
        }

        // 找到结果，返回true
        if (index == word.length() - 1) {
            return word.charAt(index) == board[i][j];
        }

        // 回溯
        if (word.charAt(index) == board[i][j]) {
            visited[i][j] = true;

            if (backtrack(index + 1, i + 1, j, board, word, visited)
                    || backtrack(index + 1, i - 1, j, board, word, visited)
                    || backtrack(index + 1, i, j + 1, board, word, visited)
                    || backtrack(index + 1, i, j - 1, board, word, visited)) {
                return true;
            }

            visited[i][j] = false;
        }

        return false;
    }
```
