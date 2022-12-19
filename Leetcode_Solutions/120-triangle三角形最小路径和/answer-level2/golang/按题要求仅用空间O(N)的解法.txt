动态规划的两个关键：
1. 状态定义
类似斐波那契数列问题。对于此题可以定义一个长度为N（triangle行数）的DP数组。将triangle[N-1]的子数组放到DP数组中。以这个数组作为初始状态，由底向上推导。
2. DP方程
由于每个点的路径和path[i,j]等于triangle[i,j]加上path[i+1,j]与path[i+1,j+1]二者较小值组成。可以列出以下方程：
path[i,j] += MIN(path[i+1,j],path[i+1,j+1])
按这个想法很容易写出空间复杂度O(M*N)的解法。
其实DP数组可以仅存放当前层的各点的最短路径（历史可以弃掉），因此改写成：
DP[i,j] = triangle[i,j] + MIN(DP[i+1,j],DP[i+1,j+1])

这样就可以仅用空间O(N)解决问题。

代码：
```go
func minimumTotal(triangle [][]int) int {
    m := len(triangle)
    memo := make([]int, m)
    for i,v := range triangle[m-1] {
        memo[i] = v
    }
    for i:= m-2;i>=0;i-- {
        for j:= 0; j<=i; j++{ //注意j要从小往大，因为memo[j]可以加上memo[j]或memo[j+1]。如果反过来，在访问memo[j]时，memo[j+1]已经被修改了，得到的结果就错了
            if memo[j] < memo[j+1]{
                memo[j] += triangle[i][j] 
            }else{
                memo[j] = triangle[i][j] + memo[j+1] 
            }
        }
    }
    return memo[0]
}
```

