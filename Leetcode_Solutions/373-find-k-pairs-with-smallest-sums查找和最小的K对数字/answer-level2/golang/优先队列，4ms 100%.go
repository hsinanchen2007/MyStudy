关键思路：如果当前最小值是nums[i]+nums[j]，那么下一个最小值在nums[i+1]+nums[j]、nums[i]+nums[j+1]以及之前一轮没选中的索引对中产生。
实现：
使用go标准库"container/heap"实现优先队列。
队中元素是(i,j),优先级是nums[i]+nums[j]。
首先入队i=j=0，之后(i,j)出队，入队的是(i+1,j)和(i,j+1)，以此类推，优先队列每次出队优先级最高的（这里定义为nums[i]+nums[j]越小优先级越高）。
```go []
// An Item is something we manage in a priority queue.
type Item struct {
	key1     int
	key2     int
	priority int // The priority of the item in the queue.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil // avoid memory leak
	*pq = old[0 : n-1]
	return item
}

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	l1 := len(nums1)
	l2 := len(nums2)
	if l1 == 0 || l2 == 0 {
		return nil
	}

	res := make([][]int, 0, k)

	var pq PriorityQueue
	pq.Push(&Item{0, 0, nums1[0] + nums2[0]})
	heap.Init(&pq)

	visited := make([][]bool, len(nums1))
	for k, _ := range visited {
		visited[k] = make([]bool, len(nums2))
	}

	for pq.Len() > 0 && len(res) < k {
		e := heap.Pop(&pq).(*Item)
 		i := e.key1
		j := e.key2
		if visited[i][j] {
			continue
		}
		res = append(res, []int{nums1[i], nums2[j]})
		visited[i][j] = true
		if i+1 < l1 {
			heap.Push(&pq, &Item{i + 1, j, nums1[i+1] + nums2[j]})
		}
		if j+1 < l2 {
			heap.Push(&pq, &Item{i, j + 1, nums1[i] + nums2[j+1]})
		}
	}
	return res
}
```

