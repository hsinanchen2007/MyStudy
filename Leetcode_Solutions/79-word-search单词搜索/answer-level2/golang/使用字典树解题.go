本题没有明确说明字符范围，经过多次试错，找到了其范围是大小写字母。所以声明长度58的数组来存字符。


```go
func exist(board [][]byte, word string) bool {


    if len(board) == 0 || len(board[0]) == 0{
        return false
    }
    root := &Trie{}
    cur := root
    for _,c := range word{
        n := c - 'A'
        cur.Kids[n] = &Trie{}
        cur = cur.Kids[n]
    }
    cur.IsWord = true
    for i := range board{
        for j := range board[i] {
            if n := board[i][j] - 'A'; root.Kids[n] != nil{
                dict := map[[2]int]bool{}
                if dfs(board, i, j, root.Kids[n],dict) {
                    return true
                }
            }
        }
    }
    return false

}

func dfs(board [][]byte, i, j int, root *Trie,dict map[[2]int]bool) bool {
    if root.IsWord {
        return true
    }
    cord := [2]int{i,j}
    dict[cord] = true
    var (
        dx = [4]int{-1,1,0,0}
        dy = [4]int{0,0,-1,1}
    )
    m := len(board)
    n := len(board[0])

    for k:=0;k<4;k++{
        x := i + dx[k]
        y := j + dy[k]
        cord2 := [2]int{x,y}
        if 0<=x && x < m && 0 <=y && y< n  && root.Kids[board[x][y] - 'A'] != nil && !dict[cord2] {
            if dfs(board,x,y,root.Kids[board[x][y] - 'A'],dict) {
                return true
            }
        }

    }
    dict[cord] = false
    return false
}
type Trie struct{
    IsWord bool
    Kids    [58]*Trie
} 
```
