### 解题思路
Go没有小顶堆，自己构造

宽度优先搜索，结合木桶原理,边界最小的值即为水面的高度，利用visited 保存访问过的点
先将四周放进队列（小顶堆），每次取最小的元素，然后访问它的四周，如果是visited就跳过，如果四周高度比当前节点小就计算水的体积
并将当前节点设置为木桶最低的高度，重新入队，并设为visited标示

### 代码

```golang
func trapRainWater(heightMap [][]int) int {
	if len(heightMap) <= 2 || len(heightMap[0]) <= 2 {
		return 0
	}
	row_max := len(heightMap)
	column_max := len(heightMap[0])
	heap := Heap{}
	visited := make(map[Point]bool)
	for i := 0; i < row_max; i++ {
		heap.insert(HeapNode{i, 0, heightMap[i][0]})
		visited[Point{i, 0}] = true
		heap.insert(HeapNode{i, column_max - 1, heightMap[i][column_max-1]})
		visited[Point{i, column_max - 1}] = true
	}
	for i := 1; i < column_max-1; i++ {
		heap.insert(HeapNode{0, i, heightMap[0][i]})
		visited[Point{0, i}] = true
		heap.insert(HeapNode{row_max - 1, i, heightMap[row_max-1][i]})
		visited[Point{row_max - 1, i}] = true
	}

	sum := 0
	for heap.count > 0 {
		heapN := heap.pop()
		x, y, h := heapN.x, heapN.y, heapN.h

		idx := []int{1, -1, 0, 0}
		idy := []int{0, 0, 1, -1}

		for i := 0; i < 4; i++ {
			newx := x + idx[i]
			newy := y + idy[i]
			// 超过边界或者已经访问过
			if newx < 0 || newx > row_max-1 ||
				newy < 0 || newy > column_max-1 ||
				visited[Point{newx, newy}] {
				continue
			}
			// 比最小的边界小
			if heightMap[newx][newy] < h {
				sum += h - heightMap[newx][newy]
				heightMap[newx][newy] = h

			}
			heap.insert(HeapNode{newx, newy, heightMap[newx][newy]})
			visited[Point{newx, newy}] = true
		}

	}
	return sum
}

type Point struct {
	x int
	y int
}
type HeapNode struct {
	x int
	y int
	h int
}
type Heap struct {
	data  []HeapNode
	count int
}

// 小顶堆 从下标1开始存
func (heap *Heap) insert(v HeapNode) {
	// 空的头节点，没用的，为了下面的append
	if len(heap.data) == 0 {
		heap.data = append(heap.data, HeapNode{})
	}
	// 插入最后面
	heap.count++
	heap.data = append(heap.data, v)
	// 从下往上堆化
	i := heap.count
	for i > 0 {
		if i/2 > 0 && heap.data[i].h < heap.data[i/2].h {
			heap.data[i], heap.data[i/2] = heap.data[i/2], heap.data[i]
			i = i / 2
		} else {
			break
		}

	}
}
func (heap *Heap) pop() HeapNode {
	res := heap.data[1]
	heap.data[1] = heap.data[heap.count]
	heap.data = heap.data[:len(heap.data)-1]
	i := 1
	heap.count--
	for i <= heap.count {
		min := i
		if 2*i <= heap.count && heap.data[i*2].h < heap.data[min].h {
			min = 2 * i
		}
		if 2*i+1 <= heap.count && heap.data[i*2+1].h < heap.data[min].h {
			min = 2*i + 1
		}
		if min != i {
			heap.data[i], heap.data[min] = heap.data[min], heap.data[i]
			i = min
		} else if min == i {
			break
		}
	}

	return res
}

```