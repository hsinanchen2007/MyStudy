>原文发布于我的博客： [leetcode-cn 题解 695. 岛屿的最大面积
](https://blog.by24.cn/archives/leetcode-max-area-of-island.html)

## 解题思路

这题本身其实没啥意思，直接上 DFS 或者 BFS 一把梭就好了，但是这样做题岂不是太没意思啦。

不如换个思路，用 **并查集** 来做吧。    


首先，我们不检查 4 个方向，我们只检查 上、左 这两个方向。  
那下边、右边的邻居怎么办呢？没事儿，它们检查上边左边两个方向的时候，会找到你的。  



接下来，我们引入『爹』『儿』的概念：

> 每个土地，都是它上方或左方土地的儿子，如果有两个爹存在，那自己和上面的爹，都要认左边的土地为爹。



我们为每一片土地，都存储一下面积，分为两种情况：

- 如果这片土地是『爹土地』，就直接存储面积的数值

- 如果这片土地是『儿土地』，那就不存面积了，存一下他『爹』的坐标

注：不与其它土地接壤的土地，自己就是一块『爹土地』  



这样，我们就可以把『儿土地』的面积，收归『爹』下面存着。



直接说可能有点乱，画个简单的图示意一下：
![image.png](https://pic.leetcode-cn.com/f86eedd493024b9f0ecc9a5ac8db39534bd734fbf511024c83f6d91120e4f24b-image.png)


为了简单，我们把面积用负数存储。

一开始，我们看到的土地似乎都是当爹的，面积全都是 -1 ，直到搜索到最后一片土地。

它上面是黄色的 -1 ，赶紧认爹，爹的面积变成了 -2 ，此处将子土地标记为 2 方便识别。

但是一检查左边，这也是个爹，那带着上面的爹一起认左边为爹，左边的面积变为了 -3。



按照这样的原则，我们只需要遍历每一个单元格，并检查他们的上方和左方，就可以将所有的面积都合并到『爹土地』去存储。

例如下面的示意图，在遍历过后，大部分土地都不再存储岛屿的面积信息。

![image.png](https://pic.leetcode-cn.com/c5291cb2a396b8e616dbfeb2c7b3d1280b3528197b63f2d8f1f52af991326d32-image.png)



此处还有个小点，因为懒得初始化二维数组，我选择直接在原数组内部存储坐标信息。

因为题目中给出了 grid 的长宽限制为 50 ，可见不会超过两位数。

那么只需要简单的乘除法和取模操作，就可以临时将 xy 坐标信息合并存储进 int 格子。

（此处其实未必乘以 10 的幂，也可以乘以其它数字，或者直接位运算）

![image.png](https://pic.leetcode-cn.com/3e5233837a3866ef0f6f662788ab642f8afd4fee57206be4d46ac2dcc030ad23-image.png)



## 代码

实际写代码的时候，还需要注意一些小情况。

类似数组越界，或者没有土地，只有一块土地的情况。

特别需要注意的是，因为找爹的时候是递归查找，可能会出现左爹和上爹是同一个的情况。

```go
func maxAreaOfIsland(grid [][]int) int {
	max := 0
	NX := 4
	NY := 256

	for x, row := range grid {
		for y, cell := range row {
			if cell == 0 {
				continue
			}

			// 只有一个点的情况
			if max == 0 {
				max = -1
			}

			grid[x][y] = -1

			//处理上方存在点的情况
			up_x := x - 1
			up_y := y
			if up_x >= 0 {
				up := grid[up_x][up_y]
				for up > NY {
					up_x = up%NY/NX - 1
					up_y = up/NY - 1
					up = grid[up_x][up_y]
				}

				if grid[up_x][up_y] < 0 {
					grid[up_x][up_y] -= 1
					grid[x][y] = NX*(up_x+1) + NY*(up_y+1)
				}

				if grid[up_x][up_y] < max {
					max = grid[up_x][up_y]
				}
			}

			left_x := x
			left_y := y - 1
			//处理左侧存在点的情况
			if left_y >= 0 {
				left := grid[left_x][left_y]
				for left > NY {
					left_x = left%NY/NX - 1
					left_y = left/NY - 1
					left = grid[left_x][left_y]
				}

				// 特殊情况，找到了同一个爹
				if left_x == up_x && left_y == up_y {
					continue
				}

				if grid[left_x][left_y] < 0 {
					if up_x >= 0 && grid[up_x][up_y] < 0 {
						//如果上面有，就合并上面的
						grid[left_x][left_y] += grid[up_x][up_y]
						grid[up_x][up_y] = NX*(left_x+1) + NY*(left_y+1)
						grid[x][y] = grid[up_x][up_y]
					} else {
						//上面没有，就只管当前的
						grid[left_x][left_y] -= 1
						grid[x][y] = NX*(left_x+1) + NY*(left_y+1)
					}
				}

				if grid[left_x][left_y] < max {
					max = grid[left_x][left_y]
				}
			}

		}
	}

	return -max
}

```



因为使用原数组存储了中间信息，内存占用还不错，只可惜时间没有拿到 100%

![image.png](https://pic.leetcode-cn.com/8e61df70d9bb7b00f9c311a6579fe79ebb9f738ddf082fdf124e782ff8611955-image.png)
