这道题的主要难点在于，如果直接在细胞面板上更新细胞的状态，会影响到其他格子的计算。为什么呢？如果我们把细胞的当前状态记为 $s_0$，细胞的下一个状态记为 $s_1$ 的话。在我们更新细胞状态的时候，有些细胞的状态已经更新到 $s_1$，有些细胞的状态还停留在 $s_0$。这就出现了不一致性。

要解决这个不一致性，比较暴力的做法是直接使用一个新的细胞面板，记录细胞的下一个状态。这种解法要使用 $O(m \times n)$ 的额外空间。

那么，如何不使用额外空间呢？答案很简单，**我们利用现有空间的潜力即可**！

为什么这么说呢？以 Java 为例，`board` 二维数组中每个元素的类型为 int，保存细胞的状态，但是细胞的状态只有 1（活细胞）和 0（死细胞）两个状态。int 一共能表示 $2^{32}$ 个整数，我们却只使用了两个值，其实有大量的空间还没有利用：

![32bit](https://pic.leetcode-cn.com/b8ee04556df20b45089d51206f988da8e19011ddcbffa60cc61475831627eb08.jpg)

在这道题中，其实我们需要记录每个细胞的**当前状态**和**下一个状态**。当前状态用来给周围的细胞计算是要去活还是去死，下一个状态用来给出问题的答案。

![int2](https://pic.leetcode-cn.com/dddf90922d494e04c5bbe1f5acbebe885792f51e7225312d8df6e5bc0c4901f0.jpg)

那么，我们就利用 int 类型的变量，同时记录细胞的当前状态和下一个状态。int 类型一共有 32 位，我们用第 0 位表示细胞的当前状态（0 或 1），用第 1 位表示细胞的下一个状态（0 或 1）：

![4states](https://pic.leetcode-cn.com/ca8b9dbf543965b57af96bc8f9ef657cb60695146339e94ac44961a2426a5e68.jpg)

Amazing！我们在一个 int 类型的变量里塞下了两个变量。**为什么能不用额外空间呢？因为老子自己就是额外空间！**

接下来，我们就需要一点位运算的技巧了。假设 `board[r][c]` 表示格子 `(r, c)` 处的细胞状态，其中第 0 位表示细胞的当前状态，第 1 位表示细胞的下一个状态，那么：

+ 取出第 0 位（当前状态）：`board[r][c] & 1`
+ 取出第 1 位（下一个状态）：`board[r][c] >> 1`
+ 将第 1 位置为 1（下一个状态是活细胞）：`board[r][c] |= 2`

这三个位运算的具体道理，请仔细体会哦！

最终我们的题解代码是这样的：

```Java []
public void gameOfLife(int[][] board) {
    for (int r = 0; r < board.length; r++) {
        for (int c = 0; c < board[0].length; c++) {
            int n = liveCells(board, r, c);
            if (board[r][c] == 1) {
                if (n < 2 || n > 3) {
                    board[r][c] |= 0; // 活细胞死亡
                } else {
                    board[r][c] |= 2; // 第 1 位置 1，活细胞仍然存活
                }
            } else {
                if (n == 3) {
                    board[r][c] |= 2; // 第 1 位置 1，死细胞复活
                } else {
                    board[r][c] |= 0; // 死细胞保持原样
                }
            }
        }
    }

    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            // 把第 1 位右移只第 0 位，也就是只保留下一个状态，作为返回结果
            board[r][c] >>= 1;
        }
    }
}

// 表示周围的八个格子
int[][] moves = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1},
};

// 计算格子 (r, c) 周围的活细胞数量
int liveCells(int[][] board, int r, int c) {
    int count = 0;
    for (int[] move : moves) {
        int r2 = r + move[0];
        int c2 = c + move[1];
        // board[r2][c2] & 1 取当前状态
        if (inArea(board, r2, c2) && (board[r2][c2] & 1) == 1) {
            count++;
        }
    }
    return count;
}

// 判断 (r, c) 是否是合法坐标
boolean inArea(int[][] board, int r, int c) {
    return 0 <= r && r < board.length
        && 0 <= c && c < board[0].length;
}
```

**扩展：** 像这样的题目其实还有很多，都是利用了编码中冗余，把信息存储在额外空间中。例如，[79. 单词搜索](https://leetcode-cn.com/problems/word-search/) 这道题，利用的就是 char 类型的额外空间。推荐大家也做一下这道题~

这道题是怎么利用额外空间的呢？我们知道 C/C++ 中的 char 类型为 1 个字节，即 8 bit。但是一般 char 类型只用来表示 ASCII 码的 128 个字符，也就是说，只用到了其中的 7 个 bit。那么我们可以使用 char 类型变量的最高一位来保存额外的信息。

---

如果你觉得本文对你有帮助，欢迎关注我的公众号《面向大象编程》，其中的《LeetCode 例题精讲》系列文章正在写作，不仅有题解，更能让你学会解题的通用思路，举一反三！

![footer](https://pic.leetcode-cn.com/0b776de278ad894de3b1c5d1e0fc615a54670128ad6990d2aa318297d4938648.jpg)