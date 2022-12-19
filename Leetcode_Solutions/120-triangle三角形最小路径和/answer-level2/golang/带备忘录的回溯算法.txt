思路很简单，从一个点(i,j)的开始往下走，只有两种方式：下一步走(i+1,j)或(i+1,j+1)。然后最短路径就是取两个后续节点的最小值就行了。
比如此函数叫tranverse，由以下公式即可以算出最短路径：

tranverse(i,j) += MIN(tranverse(i+1,j), tranverse(i+1,j+1))

在此基础上，增加一个备忘录即可。

```go
func minimumTotal(triangle [][]int) int {
    
    m := len(triangle)
    n := len(triangle[m-1])
	memo := make([][]int,m)
	for i := 0;i<m;i++{
		memo[i] = make([]int,n)
	}

    
    return tranverse(0,0,m,n,memo,triangle)

}

func tranverse(i,j,m,n int, memo [][]int, triangle [][]int) int{
    if memo[i][j] == 0 {
        memo[i][j] = triangle[i][j]
    }
    if i == m-1 {
        return memo[i][j]
    }
    if memo[i+1][j]==0 {
        memo[i+1][j] = tranverse(i+1,j,m,n,memo,triangle)
    }
    if memo[i+1][j+1]==0 {
        memo[i+1][j+1] = tranverse(i+1,j+1,m,n,memo,triangle)
    }
    if memo[i+1][j] < memo[i+1][j+1] {
        return memo[i+1][j] + memo[i][j]
    }else{
        return memo[i+1][j+1] + memo[i][j]
    }
    
}
```
