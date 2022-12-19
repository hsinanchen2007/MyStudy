####  方法：特殊用途的网络 Ad-Hoc [Accepted]
我们需要模拟执行所描述的算法。它由两个主要步骤组成：粉碎糖果和掉落糖果。我们每个步骤都是单独完成的。

**算法：**
- 粉碎糖果

我们如果是按行或者列进行粉碎，那么在粉碎的过程中可能会粉碎到其他行或列的需要粉碎糖果的一部分。如果 `board` 是：

```
123
145
111
```

那么我们如果先粉碎了第一列的 `1` 糖果，那么就会影响第三行 `1` 糖果的粉碎。

为了解决这个问题，我们可以先把要粉碎的糖果做个标记。我们可以使用 `toCrush` 布尔数组来辅助，或者我们可以将糖果标记为相反数（例如，`board[i][j] = -Math.abs(board[i][j])`）。

扫描 `board` 有两个方法。让我们把  `line` 称为 `board` 的行或列。

对于每一 `line`，我们可以使用一个滑动窗口（或者 Python 中的 `itertools.groupby`）来查找相同字符的连续段。如果段的长度大于 `3`，那么就应该标记它。

或者，对于每一 `line`，我们可以查看每一 `line` 的 `width-3` 段（一段为 3 个）：如果它们都相同，那么我们应该标记这 3 个。

之后，将有标记的位置设置为 0 来粉碎糖果。

- 掉落糖果

对于每一列，我们希望所有的糖果都放在底部。一种方法是顺序遍历列中为粉碎的糖果放到栈中，然后以相反的顺序遍历列且弹出栈元素设置糖果。

或者，我们可以使用滑动窗口方法，`read` 指针读元素，`write` 指针写元素。指针以逆序遍历列元素，当 `read` 指针遇到糖果时，`write` 指针将它写下来并移动到下一个位置。然后，`write` 指针将向列的其余部分写入零。

我们在下面的解决方案中使用了这些步骤的最简单方法。

```Python [ ]
class Solution(object):
    def candyCrush(self, board):
        R, C = len(board), len(board[0])
        todo = False

        for r in xrange(R):
            for c in xrange(C-2):
                if abs(board[r][c]) == abs(board[r][c+1]) == abs(board[r][c+2]) != 0:
                    board[r][c] = board[r][c+1] = board[r][c+2] = -abs(board[r][c])
                    todo = True

        for r in xrange(R-2):
            for c in xrange(C):
                if abs(board[r][c]) == abs(board[r+1][c]) == abs(board[r+2][c]) != 0:
                    board[r][c] = board[r+1][c] = board[r+2][c] = -abs(board[r][c])
                    todo = True

        for c in xrange(C):
            wr = R-1
            for r in xrange(R-1, -1, -1):
                if board[r][c] > 0:
                    board[wr][c] = board[r][c]
                    wr -= 1
            for wr in xrange(wr, -1, -1):
                board[wr][c] = 0

        return self.candyCrush(board) if todo else board
```

```Java [ ]
class Solution {
    public int[][] candyCrush(int[][] board) {
        int R = board.length, C = board[0].length;
        boolean todo = false;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c + 2 < C; ++c) {
                int v = Math.abs(board[r][c]);
                if (v != 0 && v == Math.abs(board[r][c+1]) && v == Math.abs(board[r][c+2])) {
                    board[r][c] = board[r][c+1] = board[r][c+2] = -v;
                    todo = true;
                }
            }
        }
        for (int r = 0; r + 2 < R; ++r) {
            for (int c = 0; c < C; ++c) {
                int v = Math.abs(board[r][c]);
                if (v != 0 && v == Math.abs(board[r+1][c]) && v == Math.abs(board[r+2][c])) {
                    board[r][c] = board[r+1][c] = board[r+2][c] = -v;
                    todo = true;
                }
            }
        }

        for (int c = 0; c < C; ++c) {
            int wr = R - 1;
            for (int r = R-1; r >= 0; --r)
                if (board[r][c] > 0)
                    board[wr--][c] = board[r][c];
            while (wr >= 0)
                board[wr--][c] = 0;
        }

        return todo ? candyCrush(board) : board;
    }
}
```

**复杂度分析**

* 时间复杂度：$O((RC)^2)$。其中 $R, C$ 指的是 `board` 的行和列。
* 空间复杂度：$O(1)$，因为在 `board` 进行原地修改。