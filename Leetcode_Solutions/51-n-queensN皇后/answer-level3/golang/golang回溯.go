本质上与全排列啥的没什么区别，一招鲜吃遍天。

主要区别就是减支条件的差别。

思路是一行一行的填然后回溯

```
for j in 列：
    如果不合法
        continue
    在此行j的地方放皇后
    递归
    回溯
```
valid函数就横竖斜判断棋盘上有没有放过即可

```
var res [][]string
func solveNQueens(n int) [][]string {
    res = [][]string{}
    chessBoard := make([][]bool,n)
    for i := 0;i<n;i++ {
        chessBoard[i] = make([]bool,n)
    }
    trackBack(chessBoard,[][]byte{})
    return res
}

func trackBack(chessBoard [][]bool, track [][]byte) {
    if len(track) == len(chessBoard) {
        t := make([]string,len(track))
        for k,bs := range track {
            t[k] = string(bs)
        }
        res = append(res,t)
    }

    for j := 0;j<len(chessBoard);j++ {
        if !valid(chessBoard,len(track),j) { // 减支
            continue
        }
        bs := getLine(len(chessBoard))
        bs[j] = 'Q'
        chessBoard[len(track)][j] = true //棋盘放子
        track = append(track,bs) // 加入选择路径
        trackBack(chessBoard,track) // 递归
        track = track[:len(track)-1] // 回溯
        chessBoard[len(track)][j] = false
    }
}

func valid(chessBoard [][]bool,row,cow int) bool {
    var i,j int
    for i=0;i<row;i++{
        if chessBoard[i][cow] == true {
            return false
        }
    }

    for j = 0;j<len(chessBoard);j++ {
        if chessBoard[row][j] == true {
            return false
        }
    }

    i,j = row,cow
    for i >=0 && j>=0 {
        if chessBoard[i][j] == true {
            return false
        }
        i--
        j--
    }

    i,j = row,cow
    for i >= 0 && j< len(chessBoard) {
        if chessBoard[i][j] == true {
            return false
        }
        j++
        i--
    }
    return true
}

func getLine(n int) []byte{
    bs := make([]byte,n)
    for i:=0;i<n;i++{
        bs[i] = '.'
    }
    return bs
}
```