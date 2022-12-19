### 解题思路

BFS广度优先搜索，看注释比较容易理解。

### 代码

```golang
func orangesRotting(grid [][]int) int {
	row := len(grid)       //行
	col := len(grid[0])    //列
	all := 0               //所有橘子数量
	time := 0              //当前时间
	cur_rot := 0           //当前腐烂橘子数量
	rotten := [][2]int{}   //存储腐烂橘子坐标
	for i,j := range grid {
		for x,y := range j {
			if y != 0 {
				all++
				if y == 2 {
					rotten = append(rotten,[2]int{i,x})
					cur_rot++
				}
			}
		}
	}
	directions := [4][2]int{{0,1},{0,-1},{1,0},{-1,0}}   //四个方向
	for len(rotten) != 0 && all != cur_rot {    
		new_rotten := [][2]int{}
		for _,dr := range rotten {         //向四个方向搜索新橘子，标记为腐烂
			r,c := dr[0],dr[1]
			for _,_dr := range directions {
				_r,_c := _dr[0],_dr[1]
				new_r,new_c:=r+_r,c+_c
				if new_r>=0 && new_r<row && new_c>=0 && new_c<col { 
					if grid[new_r][new_c]==1 { 
						new_rotten=append(new_rotten,[2]int{new_r,new_c})
						grid[new_r][new_c]=2 
						cur_rot++
					}
				}
			}
		}
		rotten = new_rotten    //更新腐烂橘子的坐标集合
		time++                 //时间+1
	}
	if cur_rot == all {
		return time
	}
	return -1
}
```