![1.png](https://pic.leetcode-cn.com/bcc098e5080604b98b3bcbd77498c90e1917fef6f67809d64c3d56c96251e673-1.png)

### 解题思路
遍历周围八个点

注意：不是遍历周边最新状态，而是最初的状态
### 代码

```golang
func gameOfLife(board [][]int)  {
    temp := make([][]int, len(board))
    for i := 0;i < len(board);i++ {
        temp[i] = make([]int, len(board[i]))
    }
    for i := 0;i < len(board);i++ {
        for j := 0;j < len(board[i]);j++ {
            nums := 0
            // 上面
            if i - 1 >= 0 {
                nums += board[i-1][j]
            }
            // 左面
            if j - 1 >= 0 {
                nums += board[i][j-1]
            }
            // 下面
            if i + 1 < len(board) {
                nums += board[i+1][j]
            }
            // 右面
            if j + 1 < len(board[i]) {
                nums += board[i][j+1]
            }
            // 左上
            if i - 1 >= 0 && j - 1 >= 0 {
                nums += board[i-1][j-1]
            }
            // 右上
            if i - 1 >= 0 && j + 1 < len(board[i]) {
                nums += board[i-1][j+1]
            }
            // 左下
            if i + 1 < len(board) && j - 1 >= 0  {
                nums += board[i+1][j-1]
            }
            // 右下
            if j + 1 < len(board[i]) && i + 1 < len(board) {
                nums += board[i+1][j+1]
            }
            temp[i][j] = board[i][j]
            switch {
                case nums < 2: temp[i][j] = 0
                case nums == 3 && temp[i][j] == 0: temp[i][j] = 1
                case nums > 3: temp[i][j] = 0 
            }
        }
    }
    copy(board, temp)
}
```