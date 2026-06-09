读懂题目是关键。

二维数组：[1] 表示在 (0,0) 这个格子里放置了一个正方体，结果为6
[2] 表示在(0,0) 格子里叠放了两个，所以会减少两个面，即结果为6-2 = 4

要求事N*N 的网格，
所以观察[[1,1],[1,1]],有四个立方体，所以总共有4*6 = 24 个立方体.
但是同时有4个接触面，即结果为: 24 - 4 * 2 = 16.

那么此时可知，对于任何立方体，一个接触面会减少两个面积。

考虑特殊情况，比如一行排列高度不等，比如有:[1,2]这种，表示(0,0)网格方一个，(0,1)网格放两个，
那么在横向就要以矮的网格作为计算标准。

同理，发散到N*N 的网格，不管事纵向还是横向都以矮的网格作为计算标准:
`min(grid[i-1][j],grid[i][j])
 min(grid[i][j-1],grid[i][j])`

代码如下，golang实现，90%
```
func surfaceArea(grid [][]int) int {
    if len(grid) == 0{
        return 0
    }

    count := 0
    sum := 0

    for i:=0;i<len(grid);i++ {
        for j:=0;j<len(grid);j++ {
            if grid[i][j] == 0{
                continue
            }
            sum += grid[i][j]
            count += grid[i][j] - 1
            if j-1 >=0 {
                count += Min(grid[i][j-1],grid[i][j])
            }
            if i-1 >=0 {
                count += Min(grid[i-1][j],grid[i][j])
            }
            // fmt.Println(i,j,count,sum)
        }
    }
    return sum*6 - count*2
}

func Min(a,b int) int {
    if a<b {
        return a
    }
    return b
}
```


