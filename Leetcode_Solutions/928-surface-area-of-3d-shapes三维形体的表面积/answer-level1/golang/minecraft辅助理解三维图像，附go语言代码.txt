刚看到这个问题的时候，网格，1*1*1，这不就是mc么.. 

看到给的样例，马上打开mc (玩起了游戏并且逐渐忘记做题)

题目给出的几个样例的三维图像分别是这样的
![image.png](https://pic.leetcode-cn.com/b723011772671abd70b82642caf081e5dc8be4d1eb4cf7d5b6dd65b13ec1cfcf-image.png)

其中，第二个样例`[[1,2],[3,4]]`图像的背面如图所示（三视图里面，正视图的对面方向看的）
![image.png](https://pic.leetcode-cn.com/b4c3ce2ccf32f8aef42cf8a78d66a3ebd62deeb9f32d8b35ccda245d655f955d-image.png)

第四个样例的 `[[2,2,2],[2,1,2],[2,2,2]]`，注意这里中间的空心只有一层，下面一层是有方块的。
![image.png](https://pic.leetcode-cn.com/bd59441ac39cab2b7edb0ed673749813615bfacf8a4b8c4636211df033c0b14d-image.png)

附上go语言的代码，思路和大家差不多，先算每个点不计算相邻点的侧面重合的表面积之和，然后减去重叠的部分，注意这里重叠的部分要乘以二，因为只计算和上一排的同一个位置和当前方块的左边方块的重合，
```go

func surfaceArea(grid [][]int) int {
	area := 0
	for i, row := range grid {
		for j, level := range row {
			if level > 0 {
				area += level*4 + 2
				if i > 0 {
					area -= findMin(grid[i-1][j], level) * 2
				}
				if j > 0 {
					area -= findMin(grid[i][j-1], level) * 2
				}
			}
		}
	}
	return area
}

func findMin(i, j int) int {
	if i > j {
		return j
	}
	return i
}

```
耗时超90%内存超100% 还行