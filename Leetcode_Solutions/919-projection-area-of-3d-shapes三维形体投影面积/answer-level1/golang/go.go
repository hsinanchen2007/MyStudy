### 解题思路
此处撰写解题思路

### 代码

```golang
func projectionArea(grid [][]int) int {
	x:=0
//xy面上 只要 grid[i][j]大于0 即可
//在xz，yz面上是行的最大值累加，列的最大值累加
	for i:=0;i< len(grid);i++{
		y:=0
		z:=0
		for j:=0;j< len(grid[0]);j++{
			if grid[i][j]!=0{
				x++
			}
			if y<grid[i][j]{
				y=grid[i][j]
			}
			if z<grid[j][i]{
				z=grid[j][i]
			}
		}
		x+=y+z
	}
	return x
}
```