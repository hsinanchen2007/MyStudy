### 解题思路：
以下图为例：

![image.png](https://pic.leetcode-cn.com/a50d08ec7c1a2def0aa323cc03414730f991ffe0a2bf95d16da73187c6f21426-image.png){:width=300}
{:align=center}

当我们需要计算横坐标为 `x`， 纵坐标分别为 `y1 y2`, 即正方形其中的一条边为 `grid[x][y1]->grid[x][y2]`。

比如 `x = 1`, `y1 = 0`, `y2 = 2`,我们可以获得最上面的那条边，正方形的边长为 `y2 - y1 + 1`。已知两个顶点，我们可以很容易的得到另外的三条边
![leetcode1.gif](https://pic.leetcode-cn.com/cf81e0642e0138ddeb96f9e3d94dfcd2597daf96402e9e77019760c7c64f3c34-leetcode1.gif){:width=900}
既然已经知道对应的 4 条边，那么只需要计算每条边所有的点是否都是 1，就可以知道是否满足要求。我们当然不能傻傻的每次都是全部遍历一边。

因为所有的值只有 0 和 1，
我们可以计算每个点到该行（该列）的0点的所有值的和，那么 `grid[x][y1]->grid[x][y2]`的 1 的个数为：`sum[x][y2] - sum[x][y1-1]`。分别计算行和列（加入 0 行，方便计算）
### 代码如下：

```go [-Go]
for i := 1; i <= len(grid); i++ {
	for j := 1; j <= len(grid[i-1]); j++ {
		gx[i][j] = gx[i][j-1] + grid[i-1][j-1]
		gy[i][j] = gy[i-1][j] + grid[i-1][j-1]
	}
}
```
然后我们计算每条边的大小即可。

```go [-Go]
func largest1BorderedSquare(grid [][]int) int {
	gx := make([][]int, len(grid)+1)
	gy := make([][]int, len(grid)+1)
	for i := 0; i <= len(grid); i++ {
		gx[i] = make([]int, len(grid[0])+1)
		gy[i] = make([]int, len(grid[0])+1)
	}
	for i := 1; i <= len(grid); i++ {
		for j := 1; j <= len(grid[i-1]); j++ {
			gx[i][j] = gx[i][j-1] + grid[i-1][j-1]
			gy[i][j] = gy[i-1][j] + grid[i-1][j-1]
		}
	}
	max := 0
	for x := 1; x < len(gx); x++ {
		for y := 1; y < len(gx[x]); y++ {
			for y1 := len(gx[x]) - 1; y1 >= y; y1-- {
				l := y1 - y + 1
				if l <= max {
					break
				}
				if x+y1-y >= len(gy) || x+y1-y >= len(gx) {
					continue
				}
				if gx[x][y1]-gx[x][y-1] != l {
					continue
				}
				if gx[x+y1-y][y1]-gx[x+y1-y][y-1] != l {
					continue
				}
				if gy[x+y1-y][y]-gy[x-1][y] != l {
					continue
				}
				if gy[x+y1-y][y1]-gy[x-1][y1] != l {
					continue
				}
				max = l
			}
		}
	}
	return max * max
}


```
