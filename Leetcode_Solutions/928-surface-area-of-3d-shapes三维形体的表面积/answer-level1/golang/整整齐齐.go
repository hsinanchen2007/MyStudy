### 解题思路
顶和底面积一定一样，侧面只算z轴

### 代码

```golang
func surfaceArea(grid [][]int) int {
    edge := 0
    bottom := 0
    for i := range grid{
        for j := range grid[i]{
            if grid[i][j] != 0{
                bottom += 1
                if i == 0{
                    edge += grid[i][j]
                }else if grid[i][j] > grid[i-1][j]{
                    edge += grid[i][j] - grid[i-1][j]
                }

                if j == 0{
                    edge += grid[i][j]
                }else if grid[i][j] > grid[i][j-1]{
                    edge += grid[i][j] - grid[i][j-1]
                }

                if i == len(grid)-1{
                    edge += grid[i][j]
                }else if grid[i][j] > grid[i+1][j]{
                    edge += grid[i][j] - grid[i+1][j]
                }

                if j == len(grid[i])-1 {
                    edge += grid[i][j]
                }else if grid[i][j] > grid[i][j+1]{
                    edge += grid[i][j] - grid[i][j+1]
                }
            }
        }
    }
    return edge + bottom * 2
}
```