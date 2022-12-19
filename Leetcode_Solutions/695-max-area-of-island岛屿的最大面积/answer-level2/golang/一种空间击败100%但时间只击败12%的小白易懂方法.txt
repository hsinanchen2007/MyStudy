### 解题思路
这里和我200题的思路是一样的，我们可以在bfs的过程中记录下当前的area面积，然后在和预设的max比较。
这个方法的时间复杂度好像比较高，但是吧，容易看懂。

具体思路是这样的：我们先判断边界(LC的边界时不得不注意的东西)，然后我们定义一个max为最大面积和一个cnt为当前面积。进循环，如果这个点是1，我们就bfs他，bfs的思路无非就是在边界范围内找上下左右四个点是不是1，是的话值置0，cnt++。最后看看这块岛的面积和max的比较有没有更大，更大的话就替换一下。

//感觉复杂度肯定不是最优的，这种思路如果有大佬有优化的方法可以留言教教我，不胜感激orz


### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
    if len(grid)==0 || (len(grid)>0 && len(grid[0])==0){
		return 0
	}
	max :=0
	cnt:=0
	var bfs func(i int,j int)
	bfs = func(i int,j int) {
		if i>=1 && grid[i-1][j]==1{
			grid[i-1][j]=0
			cnt++
			bfs(i-1,j)
		}
		if (i+1)<len(grid) && grid[i+1][j]==1{
			grid[i+1][j]=0
			cnt++
			bfs(i+1,j)
		}
		if j>=1 && grid[i][j-1]==1{
			grid[i][j-1]=0
			cnt++
			bfs(i,j-1)
		}
		if (j+1)<len(grid[0]) && grid[i][j+1]==1{
			grid[i][j+1]=0
			cnt++
			bfs(i,j+1)
		}
	}
	
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid[0]);j++{
			if grid[i][j]==1{
				cnt=1
                grid[i][j]=0
				bfs(i,j)
				if cnt>max{
					max = cnt
				}
			}
			//fmt.Println(grid)
		}
	}
	return max
}
```