### 解题思路
遍历每一位 check下一次的状态 
针对 board[i][j] 周围的八个位置 每个位置如board[i][j+1]&1 == 1 为活的 count加1
最后根据
```golang
// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 if board[i][j]&1 == 1 {
        if count < 2 || count > 3 {
            return false
        }else {
            return true
        }
    } 
// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
 if board[i][j]&1 == 0 && count == 3 {
        return true
    }else {
    return false
}
```
check 为活 结果记录在第二位

最后遍历把每个细胞状态值 右移一位 board[i][j] >> 1 
### 代码

```golang
func gameOfLife(board [][]int)  {
 
    for i := 0; i< len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            if check(board, i, j) {
                // 直接记录在第二位
                board[i][j] |= 2
            }
        }
    }
    for i := 0; i< len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            // 把第二位挪到第一位
            board[i][j] >>= 1
        }
    }
}

func check(board [][]int, i, j int) bool {
    count := 0

    if i < len(board)-1  && board[i+1][j]&1 == 1{
        count++
    }
    if i > 0  && board[i-1][j]&1 == 1{
        count++
    }
    if j < len(board[0])-1 && board[i][j+1]&1 == 1{
        count++
    }
    if j > 0 && board[i][j-1]&1 == 1{
        count++
    }
    if  i < len(board)-1 && j < len(board[0])-1 && board[i+1][j+1]&1 == 1{
        count++
    }
    if i > 0 && j > 0 && board[i-1][j-1]&1 == 1{
        count++
    }
    if i > 0 && j < len(board[0])-1 && board[i-1][j+1]&1 == 1 {
        count++
    }
    if i < len(board)-1 && j > 0 && board[i+1][j-1]&1 == 1 {
        count++
    }
    // 根据 count 判断下一轮状态
    if board[i][j]&1 == 1 {
        if count < 2 || count > 3 {
            return false
        }else {
            return true
        }
    } 
    if board[i][j]&1 == 0 && count == 3 {
        return true
    } 
    return false
}

```