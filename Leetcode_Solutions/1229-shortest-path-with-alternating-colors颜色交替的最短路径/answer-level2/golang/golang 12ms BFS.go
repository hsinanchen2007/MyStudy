### 解题思路：
看到最短路径，首先想到的就是 `BFS`。这题主要的难点在于颜色的变换

遇到 `dfs/bfs` 相关问题，先转换成多维数组，再写一个 `visited`，标记是否被访问过。后面就是简单的状态转换

我们考虑从 `A->B` 的所有情况，并计算出下一步的颜色保存到队列中即可。再通过队列不断往下走。

![image.png](https://pic.leetcode-cn.com/1456a2bf0f87b5e36df775035cc597b0cb2ef27258b864caf92f75618288c203-image.png){:width=500}
{:align=center}

合并相同情况后的状态转换，其中 `none` 是 $0$ 节点开始的状态。其他节点不存在这种情况，具体看注释。
### 代码：

``` [-GO]
switch nowColor {
case NONE, ALL:
	diff = grid[nowIdx][i]
default:
	if grid[nowIdx][i] == nowColor {
		diff = -1
	} else {
		diff = ex(nowColor)
	}
}

func ex(color int) int {
	if color == RED {
		return BLUE
	}
	return RED
}
```



``` [-GO]
var (
	NONE = 0
	RED  = 1
	BLUE = 2
	ALL = 3
)

func ex(color int) int {
	if color == RED {
		return BLUE
	}
	return RED
}

func shortestAlternatingPaths(n int, red_edges [][]int, blue_edges [][]int) []int {
	grid := make([][]int, n)
	ret := make([]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, n)
		ret[i] = -1
	}
	// 二维数组记录有向图，既有红色又有蓝色， 就标记为ALL
	for i := 0; i < len(red_edges); i++ {
		grid[red_edges[i][0]][red_edges[i][1]] += RED
	}
	for i := 0; i < len(blue_edges); i++ {
		grid[blue_edges[i][0]][blue_edges[i][1]] += BLUE
	}
	queue := [][3]int{[3]int{0, 0, 0}} // 队列存储当前状态 idx, count, color
	visited := make(map[[2]int]bool) // 是否被访问，idx， color。注意，同一个节点不同的颜色表示的状态不同
	ret[0] = 0
	start, end := 0, 0
	for start <= end {
		nowIdx, nowCount, nowColor := queue[start][0], queue[start][1], queue[start][2]
		start++
		for i := 0; i < n; i++ {
			if grid[nowIdx][i] > 0 {
				// 颜色转换
				var diff int
				switch nowColor {
				case NONE, ALL:
					diff = grid[nowIdx][i]
				default:
					if grid[nowIdx][i] == nowColor {
						diff = -1
					} else {
						diff = ex(nowColor)
					}
				}
				// 同色或已访问过，不需要再计算
				if diff == -1 || visited[[2]int{i, diff}] {
					continue
				}
				visited[[2]int{i, diff}] = true

				// 计算最小路径
				if ret[i] == -1 {
					ret[i] = nowCount + 1
				} else {
					ret[i] = min(ret[i], nowCount + 1)
				}

				// 入队
				queue = append(queue, [3]int{i, nowCount + 1, diff})
				end++
			}
		}
	}
	return ret
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

```
