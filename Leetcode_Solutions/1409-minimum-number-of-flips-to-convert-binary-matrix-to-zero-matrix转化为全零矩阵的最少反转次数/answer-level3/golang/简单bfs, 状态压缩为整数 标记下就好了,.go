> 很抱歉 开始读错题了 , 导致代码有点乱,  加上初学`Go` 代码风格也很丑. 

状态最多 `1<<(n+m)`个,
最小步数, 考虑`bfs`
状态标记的时候 因为只有`0`或`1`, 所以只要状态压缩一下就好了. 方便vis标记.
同时`0`与`1`互换可以用`异或`操作实现, 比较简单.

```go
type node struct {
    val int
    step int
}

var fx = []int{0, 0, 1, -1}
var fy = []int{1, -1, 0, 0}
func getNum(x, y, n, m int) int {
    var ans = 0
    ans |= 1<<(x*m+y)
    for i:=0; i<4; i++ {
        xx := x + fx[i]
        yy := y + fy[i]
        if xx < 0 || xx >= n {
            continue
        }
        if yy < 0 || yy >= m {
            continue
        }
        ans |= 1<<(xx*m+yy)
    }
    return ans 
}

func geth(mat [][]int) int {
    var val = 0
    for _, raw := range mat {
        for _, v := range raw {
            val = val *2 + v
        }
    }
    return val
}

func bfs(qqq, length, n, m int) int {
    queue := list.New()
    queue.PushBack(node{qqq, 0})
    
    vis := make([]int, 512+7)
    
    for queue.Len() > 0 {
        qf := queue.Front()
        u := qf.Value.(node)
        fmt.Println(u.val, u.step)
        if u.val == 0 {
            return u.step
        }
        queue.Remove(qf)
        
        for i:=0; i < n; i++ {
            for j:=0; j < m; j++ {
                v := u.val ^ getNum(i, j, n, m)
                if vis[v] == 1 {
                    continue
                } 
                vis[v] = 1
                queue.PushBack(node{v, u.step + 1})
            }
        }
        
    }
    return -1
}

func minFlips(mat [][]int) int {
    var n = len(mat)
    var m = len(mat[0])
    var length = m * n
    var val = geth(mat)
    fmt.Println(n,m, "---")
    return bfs(val, length, n, m)
}
```