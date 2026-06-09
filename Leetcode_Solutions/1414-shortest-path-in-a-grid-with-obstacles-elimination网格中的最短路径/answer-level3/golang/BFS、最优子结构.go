### 思路

- 基于普通的深度优先搜索，这里可以穿过一定数量的障碍物，搜索的范围变成了三维（假设第三维表示消除的障碍数），但是直接搜索的话，因为搜索范围过大，将会导致超时。

- 不难发现，搜索时，很有可能回到了同一个点，但是消除数不同。因此当搜索到同一点时，需要根据改点经过消除的障碍数目进行剪枝。只有在新的路径消除障碍数更少时，才入队，这里的队指的是BFS的节点队列。

- 因此，在传统BFS的基础上，需要保存一个点在不同消除数情况下的访问标记、以及每个点的最优子结构（到达当前节点的最少消除数）

- [转自：https://blog.csdn.net/the_first_snow/article/details/103551346](https://blog.csdn.net/the_first_snow/article/details/103551346)

### 实现细节

- 这一部分是下文代码中部分细节的解释，与总体思路不冲突

- 根据题目要求，最多存在 40 * 40 个点，没必要开辟一个 40 * 40 * 1600 的数组保存访问状态，这里使用的是 map ，根据行、列、以及消除数计算得到一个唯一的键即可

- 在进行BFS时，使用的队列是通过链表模拟的，通过移动首指针、尾指针实现。

### 代码

```golang
var gridData *[][]int
var direct = [][]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
var head, tail *BfsEle
var width, height, maxClear int
var flagMap map[int]bool // 访问标记
var bestStep [40][40]int16  // 最优子结构记录
 
type BfsEle struct {
	row, col, k, step int
	next              *BfsEle
}
 
func addEle() {
	for _, nowDirect := range direct {
		newRow := head.row + nowDirect[0]
		newCol := head.col + nowDirect[1]
		if newRow < 0 || newRow == height || newCol < 0 || newCol == width || flagMap[head.k*10000+newRow*100+newCol] {
			continue
		}
		newEle := BfsEle{newRow, newCol, -1, head.step + 1, nil}
		if (*gridData)[newRow][newCol] == 0 {
			newEle.k = head.k
		} else if head.k+1 <= maxClear {
			newEle.k = head.k + 1
		}
		if newEle.k != -1 && bestStep[newRow][newCol] > int16(newEle.k) { // 有效则追加，无效则不动
			bestStep[newRow][newCol] = int16(newEle.k)
			tail.next = &newEle
			tail = tail.next
			flagMap[newEle.k*10000+newRow*100+newCol] = true
		}
	}
}
 
func shortestPath(grid [][]int, k int) int {
	height = len(grid)
	width = len(grid[0])
	gridData = &grid
	flagMap = make(map[int]bool)
	for i:=0; i<height; i++{
		for j:=0; j<width; j++{
			bestStep[i][j] = 1600
		}
	}
	flagMap[0] = true
	bestStep[0][0] = 0
	head = &BfsEle{0, 0, 0, 0, nil}
	tail = head
	maxClear = k
	for head != nil {
		if head.col == width-1 && head.row == height-1 {
			return head.step
		}
		addEle()
		head = head.next
	}
	return -1
}
```