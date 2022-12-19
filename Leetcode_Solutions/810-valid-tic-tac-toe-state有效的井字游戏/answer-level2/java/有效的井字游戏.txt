#### 方法一：分类讨论【通过】

**思想**

考虑井字游戏板生效的必要条件：

* 因为所有的玩家轮流放棋，所以 `X` 的数量一定大于等于 `O` 的数量。

* 获胜的玩家一定是在自己放棋后赢得比赛。

  * 如果第一个玩家获胜，则 `X` 的数量比 `O` 的数量多 1。
  * 如果第二个玩家获胜，则 `X` 的数量与 `O` 的数量相同。

* 游戏板上不可能同时出现 3 个 `X` 在一行 和 3 个 `O` 在另一行。因为一旦有玩家获胜，游戏结束，另外一名玩家不能再放棋。

事实证明，以上条件包含了游戏板生效的全部情况。可以通过反证法验证上面分类条件的正确性。在任何一局比赛中，只能有 3 种结果，要么没有玩家获胜，要么只有一个玩家获胜，要么两个玩家都获胜。在前两种情况下，通过检查两种棋的数量关系即可验证是否有效。最后这一种情况下，不允许两个玩家同时获胜。

**算法**

统计游戏板上 `X` 和 `O` 的数量并记录在 `xCount` 和 `oCount` 中。

使用函数 `win(player)` 检查玩家是否获胜，它检查在棋盘的 3 行，3 列和 2 条对角线上是否有该玩家的连续 3 枚棋子。

```java [solution1-Java]
class Solution {
    public boolean validTicTacToe(String[] board) {
        int xCount = 0, oCount = 0;
        for (String row: board)
            for (char c: row.toCharArray()) {
                if (c == 'X') xCount++;
                if (c == 'O') oCount++;
            }

        if (oCount != xCount && oCount != xCount - 1) return false;
        if (win(board, 'X') && oCount != xCount - 1) return false;
        if (win(board, 'O') && oCount != xCount) return false;
        return true;
    }

    public boolean win(String[] B, char P) {
        // B: board, P: player
        for (int i = 0; i < 3; ++i) {
            if (P == B[0].charAt(i) && P == B[1].charAt(i) && P == B[2].charAt(i))
                return true;
            if (P == B[i].charAt(0) && P == B[i].charAt(1) && P == B[i].charAt(2))
                return true;
        }
        if (P == B[0].charAt(0) && P == B[1].charAt(1) && P == B[2].charAt(2))
            return true;
        if (P == B[0].charAt(2) && P == B[1].charAt(1) && P == B[2].charAt(0))
            return true;
        return false;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def validTicTacToe(self, board):
        FIRST, SECOND = 'XO'
        x_count = sum(row.count(FIRST) for row in board)
        o_count = sum(row.count(SECOND) for row in board)

        def win(board, player):
            for i in xrange(3):
                if all(board[i][j] == player for j in xrange(3)):
                    return True
                if all(board[j][i] == player for j in xrange(3)):
                    return True

            return (player == board[1][1] == board[0][0] == board[2][2] or
                    player == board[1][1] == board[0][2] == board[2][0])

        if o_count not in {x_count-1, x_count}: return False
        if win(board, FIRST) and x_count-1 != o_count: return False
        if win(board, SECOND) and x_count != o_count: return False

        return True
```

**复杂度分析**

* 时间和空间复杂度：$O(1)$。