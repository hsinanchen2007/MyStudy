### 解题思路

采用BFS方法，具体看注释。

### 代码

```golang
type point struct {
	x int
	y int
}
func maxDistance(grid [][]int) int {
	var (
		areas []*point
		res int
		dx = [4]int{1,-1,0,0}
		dy = [4]int{0,0,1,-1}    //方向数组
	)
	for i,j := range grid {
		for k,v := range j {
			if v == 1 {
				areas = append(areas,&point{i,k})   //先把所有的陆地坐标记录下来
			}
		}
	}
	if len(areas) == 0 || len(areas) == len(grid) * len(grid[0]) {  //如果地图上只有陆地或者海洋，返回-1
		return -1
	}
	for len(areas) != 0 {
		res++		//记录搜索次数
		tmp := areas
		areas = []*point{}
		for _,val := range tmp {
			for i := 0;i < 4;i++ {
				if val.x + dx[i] >= 0 && val.x + dx[i] < len(grid) && val.y + dy[i] >= 0 && val.y + dy[i] < len(grid[0]) && grid[val.x + dx[i]][val.y + dy[i]] == 0 {  //保证不越界的情况下，找到陆地相邻的海洋
					grid[val.x + dx[i]][val.y + dy[i]] = 1
					areas = append(areas,&point{val.x + dx[i],val.y + dy[i]})
				}
			}

		}
	}
	return res - 1		//注意这里要-1才是结果
}
```