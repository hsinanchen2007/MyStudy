### 解题思路
确定方位，如例子{{1,2},{3,4}}
![无标题.png](https://pic.leetcode-cn.com/9eb9af773e61d794bb8a733c9817dc3d26c01c2c2b509bf25f0e4162c21e0cc6-%E6%97%A0%E6%A0%87%E9%A2%98.png)

分5中情况(上下，前，后，左，右)
1. 上下：通过是否有方块判断。是：2；否：0
```
//up down
if grid[i][j] > 0 {
	sum += 2
}
```
2. 前：判断行
```
//front
if i > 0 {
	sum += max(grid[i][j]-grid[i-1][j], 0)
}else {
	sum += grid[i][j]
}
```
3. 后：判断行
```
//black
if i < i_index-1 {
	sum += max(grid[i][j]-grid[i+1][j], 0)
}else {
	sum += grid[i][j]
}
```
4. 左：判断列
//left
if j > 0 {
	sum += max(grid[i][j]-grid[i][j-1], 0)
}else {
	sum += grid[i][j]
}
5. 右：判断列
```
//right
if j < j_index-1 {
	sum += max(grid[i][j]-grid[i][j+1], 0)
}else {
	sum += grid[i][j]
}		
```



### 代码

```golang
func surfaceArea(grid [][]int) int {
	max := func(a, b int) int {
		if a > b {
			return a
		}else {
			return b
		}
	}
	var sum = 0
	i_index := len(grid)
	j_index := len(grid[0])
	for i:=0; i<i_index; i++ {
		for j:=0; j<j_index; j++ {
			//up down
			if grid[i][j] > 0 {
				sum += 2
			}
			//front
			if i > 0 {
				sum += max(grid[i][j]-grid[i-1][j], 0)
			}else {
				sum += grid[i][j]
			}
			//black
			if i < i_index-1 {
				sum += max(grid[i][j]-grid[i+1][j], 0)
			}else {
				sum += grid[i][j]
			}
			//left
			if j > 0 {
				sum += max(grid[i][j]-grid[i][j-1], 0)
			}else {
				sum += grid[i][j]
			}
			//right
			if j < j_index-1 {
				sum += max(grid[i][j]-grid[i][j+1], 0)
			}else {
				sum += grid[i][j]
			}
		}
	}
	return sum
}
```