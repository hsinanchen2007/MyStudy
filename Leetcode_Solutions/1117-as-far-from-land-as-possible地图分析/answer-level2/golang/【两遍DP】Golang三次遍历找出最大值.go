### 解题思路
第一次初始化将DP矩阵初始化，海岛的地方置0，因为距离陆地的距离是0，别的地方置201，因为不可能距离达到201。统计海岛数目，如果等于0或者等于矩阵面积，那就可以直接返回-1。
第一次从左上出发，找找值为201位置，值设置为附近最小值+1，第二次从右下出发往左上找，同理，并同时找最大值。
//这个算法应该不能算BFS吧，只是看到地图问题第一反应是BFS，但是后来还是做成了DP，没改名字orz

### 代码

```golang
func maxDistance(grid [][]int) int {
    max:=-1
	dp:=make([][]int,len(grid))
	cnt:=0
	for i:=0;i<len(grid);i++{
		dp[i]=make([]int,len(grid[0]))
		for j:=0;j<len(grid[0]);j++{
			if grid[i][j]==1{
				dp[i][j]=0
				cnt++
			}else{
				dp[i][j]=201
			}
		}
	}
	if cnt==len(grid)*len(grid) || cnt==0{
		return -1
	}
	var min func(nums []int)int
	min = func(nums []int)int{
		minnum := nums[0]
		for i:=1;i<len(nums);i++{
			if minnum>nums[i]{
				minnum = nums[i]
			}
		}
		return minnum
	}
	var bfs func(x int,y int)
	bfs = func(x int,y int){
		if  dp[x][y]!=0{
			nums := []int{}
			if x-1>=0{
				nums = append(nums,dp[x-1][y] )
			}
			if x+1<len(grid){
				nums = append(nums,dp[x+1][y] )
			}
			if y-1>=0{
				nums = append(nums,dp[x][y-1] )
			}
			if y+1<len(grid){
				nums = append(nums,dp[x][y+1] )
			}
			dp[x][y] = min(nums)+1
		}
	}
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid);j++{
			bfs(i,j)
		}
	}
	for i:=len(grid)-1;i>=0;i--{
		for j:=len(grid)-1;j>=0;j--{
			bfs(i,j)
			if dp[i][j]>max{
				max = dp[i][j]
			}
		}
	}
	// fmt.Println(dp)
	return max
}
```