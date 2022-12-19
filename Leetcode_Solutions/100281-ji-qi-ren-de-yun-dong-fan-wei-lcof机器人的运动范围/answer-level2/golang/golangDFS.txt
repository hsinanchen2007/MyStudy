### 解题思路
比较简单的DFS实现方法  搬运评论区大佬的  吐槽一下  golang初始化多维切片好麻烦

### 代码

```golang
func movingCount(m int, n int, k int) int {
    vis := make([][]bool, m + 1)
    for i := 0; i < len(vis); i++ {
        vis[i] = make([]bool, n + 1)
    }
    return dfs(0,0, m, n, k, vis)
}

func dfs(i, j, m, n, k int, vis [][]bool) int {
    if i < 0 || i >= m || j < 0 || j >= n || (i/10 + i%10 + j/10 + j%10) > k || vis[i][j] {
        return 0;
    }
    vis[i][j] = true
    return dfs(i + 1, j, m, n, k, vis) + dfs(i - 1, j, m, n, k, vis) + dfs(i, j + 1, m, n, k, vis) + dfs(i, j - 1, m, n, k, vis) + 1;
}
```