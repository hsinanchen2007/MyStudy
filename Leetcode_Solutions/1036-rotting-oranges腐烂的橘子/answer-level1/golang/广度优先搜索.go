### 解题思路
此处撰写解题思路

### 代码

```golang
func orangesRotting(grid [][]int) int {
	mins:=0
	//新鲜橘子的个数
	nums:=0
	//0min时的所有腐烂的橘子
	rotOranges:=make([][]int,0)
	for i:=0;i< len(grid);i++{
		for j:=0;j< len(grid[0]);j++{
			if grid[i][j]==1{
				nums++
			}else if grid[i][j]==2{
				rotOranges= append(rotOranges, []int{i,j})
			}
		}
	}
	for nums>0&& len(rotOranges)>0{
		mins++
		n:= len(rotOranges)
        //每次循环n次 将本次的quene全部遍历掉
		for i:=0;i<n;i++{
			one:=rotOranges[0]
			rotOranges=rotOranges[1:]
			x:=one[0]
			y:=one[1]
			if x-1>=0&&grid[x-1][y]==1{
				grid[x-1][y]=2
				rotOranges= append(rotOranges, []int{x-1,y})
				nums--
			}
			if x+1<= len(grid)-1&&grid[x+1][y]==1{
				grid[x+1][y]=2
				rotOranges= append(rotOranges, []int{x+1,y})
				nums--
			}
			if y-1>=0&&grid[x][y-1]==1{
				grid[x][y-1]=2
				rotOranges= append(rotOranges, []int{x,y-1})
				nums--
			}
			if y+1<= len(grid[0])-1&&grid[x][y+1]==1{
				grid[x][y+1]=2
				rotOranges= append(rotOranges, []int{x,y+1})
				nums--
			}
		}

	}
	if nums>0{
		return -1
	}
	return mins
}
```