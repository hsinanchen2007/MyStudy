### 解题思路
用 map 来保存位置信息， string 一定要仔细看。。。一开始把判断条件那里的 "," 写成了 " "，一直过不了

### 代码

```golang
func movingCount(m int, n int, k int) int {
    visited := make(map[string]bool)
    return dfs(0,0,m,n,k,visited)
}

func dfs(x int, y int, m int, n int, k int,z map[string]bool)int{
    if x >= n || y >= m || (x%10+x/10+y%10+y/10) > k{  //判断边界和数位和
        return 0
    }
    if _, isVisited := z[fmt.Sprintf("%d,%d",x,y)];isVisited{//判断是否访问过
        return 0
    }
        z[fmt.Sprintf("%d,%d",x,y)] = true   //把位置信息加入 Map
        return 1 + dfs(x+1, y, m, n, k, z) + dfs(x, y+1, m, n, k, z)
}
```