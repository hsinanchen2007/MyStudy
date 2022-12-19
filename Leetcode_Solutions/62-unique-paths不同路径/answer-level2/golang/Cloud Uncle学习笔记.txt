1.递归
```
func uniquePaths(m int, n int) int {
    if m <= 0 || n <= 0 {
        return 0
    }
    if m == 1 || n == 1 {
        return 1
    }

    down := uniquePaths(m, n-1)
    right := uniquePaths(m-1, n)

    return down + right
}
```
2.二维数组，动态规划(动态递推)，时间复杂度O(m*n),空间复杂度O(m*n)
```
func uniquePaths(m int, n int) int {
    if m <= 0 || n <= 0 {
        return 0
    }

    pathArr := make([][]int, m)
    for i:=0; i<m; i++ {
        pathArr[i] = make([]int, n)
    }

    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {
            if i==0 || j==0 {
                pathArr[i][j] = 1
                continue
            }
            //递推公式
            pathArr[i][j] = pathArr[i-1][j] + pathArr[i][j-1]
        }
    }

    return pathArr[m-1][n-1]
}
```
3.一维数组，动态规划(递推),时间复杂度O(m*n),空间复杂度O(n)
```
func uniquePaths(m int, n int) int { 
    if m <= 0 || n <= 0 {
        return 0
    }

    pathArr := make([]int, n)
    pathArr[0] = 1

    for i:=0; i<m; i++ {
        for j:=1; j<n; j++ {
            pathArr[j] += pathArr[j-1]
        }
    }

    return pathArr[n-1]
}
```
