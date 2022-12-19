### 解题思路
DFS

### 代码

```golang
var ans bool
func exist(board [][]byte, word string) bool {
    ans = false

    m := len(board)
    if m==0 {
        return ans
    }

    n := len(board[0])
    if n==0 {
        return ans
    }

    if len(word)==0 {
        return ans
    }

    for i:=0;i<m;i++ {
        for j:=0;j<n;j++ {
            if board[i][j]==word[0] {
                visited := make([][]bool,m)
                for k:=0;k<m;k++ {
                    visited[k]=make([]bool,n)
                }
                dfs(board,visited,word,i,j,0)
            }
        }

        if ans {
            break
        }
    }

    return ans
}

func dfs(board [][]byte,visited [][]bool,word string,x int,y int,index int) {
    if x<0 || x>=len(board) || y<0 || y>=len(board[0]) || visited[x][y] || board[x][y]!=word[index] || ans {
        return
    }

    if index==len(word)-1 {
        ans = true
        return
    }

    visited[x][y]=true
    dfs(board,visited,word,x-1,y,index+1)
    dfs(board,visited,word,x+1,y,index+1)
    dfs(board,visited,word,x,y-1,index+1)
    dfs(board,visited,word,x,y+1,index+1)
    visited[x][y]=false
}
```