### 解题思路
![1.png](https://pic.leetcode-cn.com/319bebb04c0686dc4643bf19e02af381d5e442b09bd7aa111764741e1d48252a-1.png)

这道题的题目是真的很难懂，作为一个语文渣渣，题目读了十分钟，建议加个图来告诉大家题目的意思。他想描述的是现在有一块平面上面积为N^2区域可以同来堆立方体，例如[[1,2],[3,4]]这个数据里，3的数组下标是(1,0)那么映射到空间坐标系里就表示(1,0)这个点堆了3*1*1体积的一个立方体。
解题思路是看看这个点的值是不是0，不是0，表面积就可以先考虑加上顶面积和底面积，然后看看是不是四周比其他的高，如果不高表面积不增加，不然的话高多少增加多少。遍历完整个Grid数组，我们就可以得到表面积。
//边界处理需要注意一下


### 代码

```golang
func surfaceArea(grid [][]int) int {
    N:=len(grid)
	ans:=0
	var max func(a int,b int)int
	max = func(a int, b int) int{
		if a>b{return a}
		return b
	}
	for i:=0;i<N;i++{
		for j:=0;j<N;j++{
			if grid[i][j]!=0{
				ans+=2
			}
			if i>0{
				ans+=max(grid[i][j]-grid[i-1][j],0)
			}else{
				ans+=grid[i][j]
			}
			if i<N-1{
				ans+=max(grid[i][j]-grid[i+1][j],0)
			}else{
				ans+=grid[i][j]
			}
			if j>0{
				ans+=max(grid[i][j]-grid[i][j-1],0)
			}else{
				ans+=grid[i][j]
			}
			if j<N-1{
				ans+=max(grid[i][j]-grid[i][j+1],0)
			}else{
				ans+=grid[i][j]
			}
		}
	}
	return ans
}
```