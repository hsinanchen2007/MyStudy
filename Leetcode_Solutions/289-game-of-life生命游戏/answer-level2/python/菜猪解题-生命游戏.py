看到网上有位大佬对此类题目的解答非常精髓，凡是碰到in-place更新数组的题目，基本上都是两次遍历，逐步更新的。第一次遍历，就是要将更新后的值用其他数字来代替，避免更新后该数字对下一个数字的更新产生影响。第二次遍历，则是将所有更新后的数字对照相应关系恢复为原始数组中出现的数值。对于本题而言呢，思路如下：
`第一次遍历时也是分两种情况：
    若活细胞变成了死细胞，由1->-1， 若活细胞还是存活，由1->3；
    若死细胞变成了活细胞，由0->2， 若死细胞还是死亡，由0->-2；
第二次遍历则是将2, 3->1, -1, -2->0`

代码如下：
```Python
class Solution(object):
    def gameOfLife(self, board):
        """
        两次遍历，
        第一次遍历时也是分两种情况：
            若活细胞变成了死细胞，由1->-1， 若活细胞还是存活，由1->3；
            若死细胞变成了活细胞，由0->2， 若死细胞还是死亡，由0->-2；
        第二次遍历则是将2, 3->1, -1, -2->0
        这样可以避免每次迭代更新时上一次的细胞状态对下一次更新细胞的影响
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        def count_num(start_row, start_col, end_row, end_col):
            lives = 0
            for row in range(start_row, end_row+1):
                for col in range(start_col, end_col+1):
                    if board[row][col] in [-1, 1, 3]:
                        lives += 1
            return lives

        row_len, col_len = len(board), len(board[0])
        for row in range(row_len):
            start_row = max(0, row - 1)
            end_row = min(row_len-1, row+1)
            for col in range(col_len):
                start_col, end_col = max(0, col - 1), min(col_len-1, col+1)
                lives = count_num(start_row, start_col, end_row, end_col)
                if board[row][col] == 1:
                    lives -= 1
                    if lives < 2 or lives > 3:
                        board[row][col] = -1
                    else:
                        board[row][col] = 3
                else:
                    if lives == 3:
                        board[row][col] = 2
                    else:
                        board[row][col] = -2
        # 第二次遍历，恢复更改的值
        for row in range(row_len):
            for col in range(col_len):
                if board[row][col] >= 2:
                    board[row][col] = 1
                else:
                    board[row][col] = 0


if __name__ == "__main__":
    board = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
    Solution().gameOfLife(board)
```

执行效率能达到90%
![image.png](https://pic.leetcode-cn.com/0d595422ec2070b680ec41d73f1078c68b5d925fde9f2c24bd198530dffbe010-image.png)
