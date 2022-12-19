### 解题思路
1、使用最小堆表示队列，值越小越先开始搜索
2、边框的值先入队，使用book数组表示是否已入队
3、依次取出优先队列中的元素，按右下左上的顺序遍历，用next数组表示
4、如果发现下一步节点的高度小于当前节点高度，说明可以存储雨水，结果+=两个高度只差，同时将下一步的节点高度赋值成当前节点高度，并入队
5、重复3-4，知道队列为空

### 代码

```golang
// 上下左右四个方向
var next2 = [][]int{
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
}

// queue2 是优先队列中包含的元素。
type Queue2 struct {
	x, y int // 元素位置。
	h    int // 元素在队列中的优先级，这里对应位置的值可以表示优先级，因为我们要从小的位置开始遍历。
	// 元素的索引可以用于更新操作，它由 heap.Interface 定义的方法维护。
	index int // 元素在堆中的索引。
}

// 一个实现了 heap.Interface 接口的优先队列，队列中包含任意多个 Queue2 结构。
type PriorityQueue []*Queue2

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// 我们希望 Pop 返回的是最小值，
	// 因此这里使用小于号进行对比。
	return pq[i].h < pq[j].h
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Queue2)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // 为了安全性考虑而做的设置
	*pq = old[0 : n-1]
	return item
}

func trapRainWater(heightMap [][]int) int {
	if len(heightMap) < 3 || len(heightMap[0]) < 3 {
		return 0
	}
	n, m := len(heightMap), len(heightMap[0])

	pq := make(PriorityQueue, (n+m)*2-4)
	var book [][]int
	var result int
	for i := 0; i < n; i++ {
		var tmp = make([]int, m)
		book = append(book, tmp)
	}
	index := 0
	for i := 0; i < n; i++ {
		pq[index] = &Queue2{
			x:     i,
			y:     0,
			h:     heightMap[i][0],
			index: index,
		}
		book[i][0] = 1
		index++
		pq[index] = &Queue2{
			x:     i,
			y:     m - 1,
			h:     heightMap[i][m-1],
			index: index,
		}
		book[i][m-1] = 1
		index++
	}

	for i := 1; i < m-1; i++ {
		pq[index] = &Queue2{
			x:     0,
			y:     i,
			h:     heightMap[0][i],
			index: index,
		}
		book[0][i] = 1
		index++
		pq[index] = &Queue2{
			x:     n - 1,
			y:     i,
			h:     heightMap[n-1][i],
			index: index,
		}
		book[n-1][i] = 1
		index++
	}
	heap.Init(&pq)

	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Queue2)
		for i := 0; i <= 3; i++ {
			dx := item.x + next2[i][0]
			dy := item.y + next2[i][1]
			if dx < 0 || dx >= n || dy < 0 || dy >= m {
				continue
			}
			if book[dx][dy] == 0 {
				if heightMap[dx][dy] < item.h {
					result += item.h - heightMap[dx][dy]
					heightMap[dx][dy] = item.h // 这个赋值很关键，否则可能误伤它边上节点的值
				}
				tmp := &Queue2{
					x: dx,
					y: dy,
					h: heightMap[dx][dy],
				}
				heap.Push(&pq, tmp)
				book[dx][dy] = 1
			}
		}
	}
	return result
}
```