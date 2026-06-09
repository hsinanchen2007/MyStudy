### 解题思路
1. 创建一个和board尺寸一样的矩阵，全部是0， 用来做标记（标记已经走过的地方。
2. 遍历board矩阵，碰到和字符串word第一个元素一样的元素就开始向四周深度遍历

代码后面有一个篇幅略长的一段，是为了节省时间不然，单纯 
`
return inflect(board, indexMatrx, l+1, r, n+1, word) || inflect(board, indexMatrx, l-1, r, n+1, word) || inflect(board, indexMatrx, l, r+1, n+1, word) || inflect(board, indexMatrx, l, r+1, n+1, word)
`
时间会超

### 优化（没实现代码）：
1. 原来的代码是使用另外一个矩阵来做标记，这消耗了更多的空间，可以在原矩阵中进行改动做标记，比如遍历过的
`A`就换成'0'(简单做个思路补充)


### 代码

```golang
func exist(board [][]byte, word string) bool {
    if len(board) == 0 || len(board[0]) == 0 {
        return false
    }
    var indexMatrx [][]int

    for i := 0; i < len(board); i++ {
        var tmp []int
        for j:= 0; j < len(board[0]); j++ {
            tmp = append(tmp, 0)
        }
        indexMatrx = append(indexMatrx, tmp)
    }
    for i := 0; i<len(board); i++ {
        for j := 0; j <len(board[0]); j++ {
            if board[i][j] == byte(word[0]) {
                ret := inflect(board, indexMatrx, i, j, 0, word)
                if ret == true {
                    return true
                }
            }
        }
    } 
    return false
}

func inflect(board [][]byte, indexMatrx [][]int, l, r, n int, word string) bool {

    if l < 0 || l > len(board)-1 || r < 0 || r > len(board[0])-1 {
        return false
    }
    if indexMatrx[l][r] == 1 || board[l][r] != byte(word[n]) {
        return false
    }
    if n == len(word)-1 {
        return true
    }
    indexMatrx[l][r]++
    a := inflect(board, indexMatrx, l+1, r, n+1, word)
    if a == true {
        indexMatrx[l][r]--
        return true
    }
    b := inflect(board, indexMatrx, l-1, r, n+1, word)
    if b == true {
        indexMatrx[l][r]--
        return true
    }
    c := inflect(board, indexMatrx, l, r+1, n+1, word)
    if c == true {
        indexMatrx[l][r]--
        return true
    }
    d := inflect(board, indexMatrx, l, r-1, n+1, word)
    if d == true {
        indexMatrx[l][r]--
        return true
    }
    indexMatrx[l][r]--
    return false
}
```