## 思路:

**思路1:**

用一句话解释:不停的试数

详细解释:对于空位置,从数字`1`到`9`去试数,

如何判断这个是否是这个数,就是通过数独的规则,行列块出现相同的数字就不行.

所以,我们就可以通过回溯方法去解决,详细解释写在代码里!

因为我不太擅长 `Java` , 如果有更好的方式可以提供给我,谢谢 !

**思路2:**

在线算法,没看懂,留个坑

未完待续...

## 代码:

```python [1]
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 把所有没填数字的位置找到
        all_points = []
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    all_points.append([i, j])
        # check函数是为了检查是否在point位置k是合适的
        def check(point, k):
            row_i = point[0]
            col_j = point[1]
            for i in  range(9):
                # 检查 行
                if i != row_i and board[i][col_j] == k:
                    return False
                # 检查 列
                if i != col_j and board[row_i][i] == k:
                    return False
            # 检查块
            for i in range(row_i//3*3 , row_i//3*3+3):
                for j in range(col_j//3*3, col_j//3*3+3):
                    if i != row_i and j != col_j and board[i][j] == k:
                        return False
            
            return True
        
        def backtrack(i):
            # 回溯终止条件
            if i == len(all_points):
                return True
            for j in range(1, 10):
                # 检查是否合适
                if check(all_points[i],str(j)):
                    # 合适就把位置改过来
                    board[all_points[i][0]][all_points[i][1]] = str(j)
                    if backtrack(i+1): # 回溯下一个点
                        return True
                    board[all_points[i][0]][all_points[i][1]] = "."# 不成功把原来改回来
            return False
        
        backtrack(0)
```



```java [1]
class Solution {
    public void solveSudoku(char[][] board) {
        if (board == null || board.length == 0) return;
        List<int[]> all_points = new ArrayList<>();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') all_points.add(new int[]{i, j});
            }
        }
        backtrack(0, all_points, board);
    }

    private boolean backtrack(int i, List<int[]> all_points, char[][] board) {
        if (i == all_points.size()) return true;
        for (char c = '1'; c <= '9'; c++) {
            if (check(all_points.get(i), c, board)) {
                board[all_points.get(i)[0]][all_points.get(i)[1]] = c;
                if (backtrack(i + 1, all_points, board)) return true;
                board[all_points.get(i)[0]][all_points.get(i)[1]] = '.';

            }
        }
        return false;

    }

    private boolean check(int[] ints, char c, char[][] board) {
        int row_i = ints[0];
        int col_j = ints[1];
        for (int i = 0; i < 9; i++) {
            if (i != row_i && board[i][col_j] == c) return false;
            if (i != col_j && board[row_i][i] == c) return false;
        }
        for (int i = row_i / 3 * 3; i < row_i / 3 * 3 + 3; i++) {
            for (int j = col_j / 3 * 3; j < col_j / 3 * 3 + 3; j++) {
                if (i != row_i && j != col_j && board[i][j] == c) return false;
            }
        }

        return true;
    }
}
```

