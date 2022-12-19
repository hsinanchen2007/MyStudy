### 解题思路
公式 从第倒数第二行开始循环每一个数，所以复杂度是mxn 
dp[i,j] = min(dp[i+1,j],dp[i+1,j+1])
1 dp  二维数组 直接用它本身

2 dp 优化 一维数组 这题纠结了很久，写详细点

### 代码
```
func minimumTotal(triangle [][]int) int {
    if len(triangle) == 0 {
        return 0
    }
    dp := triangle[len(triangle) - 1]// 这里直接=最后一行
    for i:=len(triangle) - 2;i>=0;i--{ //从倒数第二行起 -2
        for j:=0;j<=i;j++{ //如题例第三行 657  循环完需要 j<= 2
            dp[j] = min( dp[j] ,dp[j+1]) + triangle[i][j]
            //fmt.Println(dp) 打印理解如何复用 dp一维数组
        }
    }
    return dp[0]
}


func min(a,b int) int{
    if a > b{
        return b
    }
    return a
}
```
```golang
func minimumTotal(triangle [][]int) int {
    if len(triangle) == 0 {
        return 0
    }
    for i:=len(triangle) - 2;i>=0;i--{
        for j:=0;j<=i;j++{
            triangle[i][j] += min(triangle[i+1][j] ,triangle[i+1][j+1])
        }
    }
    return triangle[0][0]
}


func min(a,b int) int{
    if a > b{
        return b
    }
    return a
}
```