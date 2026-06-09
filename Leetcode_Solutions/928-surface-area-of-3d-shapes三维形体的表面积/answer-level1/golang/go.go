### 解题思路
此处撰写解题思路

### 代码

```golang
func surfaceArea(grid [][]int) int {
	num:=0
	cover:=0
	for i:=0;i< len(grid);i++{
		for j:=0;j< len(grid[0]);j++{
			num+=grid[i][j]
			if grid[i][j]>0{
				cover+=grid[i][j]-1
			}
			if i>0{
				cover+=int(math.Min(float64(grid[i-1][j]),float64(grid[i][j])))
			}
			if j>0{
				cover+=int(math.Min(float64(grid[i][j-1]),float64(grid[i][j])))
			}
		}
	}
	return 6*num-cover*2
}
```