### 解题思路
遍历, 遍历的时候, 找到第一个, 然后检测第一个四周的四个字符是否与第二个匹配. 继续直到全部找完或者 4 周 4 个都不匹配. 

为了防止重复计算之前的, 每一次开始找到第一个字符匹配的时候, 复制一份临时的状态保存.

### 代码

```golang
func exist(board [][]byte, word string) bool {
    words := []byte(word)
   for i, row := range board {
       for j, _ := range row{
          if(probe(board, words, i, j, 0)) {return true;}
       }
   } 
   return false
}

func probe(board [][]byte, word []byte, i, j, k int) bool {
    if i >= len(board) || i< 0 || j>= len(board[0]) || j< 0 || board[i][j] != word[k]{return false}

    if k== len(word)-1 {return true}
    tmp := board[i][j];
    board[i][j] = '/'
    res := probe(board, word, i+1,j,k+1) || probe(board,word, i-1,j, k+ 1) || probe(board, word, i, j+1, k+1) || probe(board, word, i , j-1, k+1)

    board[i][j] = tmp
    return res
}

```