### 解题思路
此处撰写解题思路
**总体思路：总的立方体的表面积减去重叠部分的面积**
重叠有三种情况：把整体放在三维坐标上
1. z轴方向的重叠：在同一个单元格上的重叠个数
2. x轴方向的重叠：也可以说是行上面的重叠个数
3. y轴方向的重叠：也可以认为是在列上的重叠个数
### 代码

```golang
func surfaceArea(grid [][]int) int {
    cubeNum := 0
	overlap1 := 0
	overlap2 := 0
	overlap3 := 0
	for i,v := range grid{
		for j,v2 := range v{
			cubeNum += v2

			//每个单元格上的重叠个数
			if v2 > 1 {
				overlap1 += v2-1
			}

			//在行上面的重叠个数
			if i > 0 {
				if v2 > grid[i-1][j] {
					overlap2 += grid[i-1][j]
				}else {
					overlap2 += v2
				}
			}
			
			//在列上的重叠个数
			if j > 0 {
				if v2 > grid[i][j-1] {
					overlap2 += grid[i][j-1]
				}else {
					overlap2 += v2
				}
			}
		}
	}
	return cubeNum*6 - (overlap1+overlap2+overlap3)*2
}
```