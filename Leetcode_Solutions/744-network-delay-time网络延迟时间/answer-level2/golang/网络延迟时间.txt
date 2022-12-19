```golang
//	743
func networkDelayTime(times [][]int, N int, K int) int {
	// graph[i]保存i节点的相邻节点和距离元组的列表
	graph := make(map[int][][]int)
	for _, time := range times {
		graph[time[0]] = append(graph[time[0]], []int{time[1], time[2]})
	}
	dist := make(map[int]int)
	minHeap := &NodeDistMinHeap{}
	heap.Push(minHeap, NodeDist{
		node: K,
		dist: 0,
	})
	for minHeap.Len() > 0 {
		nd := heap.Pop(minHeap).(NodeDist)
		if _, ok := dist[nd.node]; ok {
			continue
		}
		dist[nd.node] = nd.dist
		for _, tuple := range graph[nd.node] {
			if _, ok := dist[tuple[0]]; !ok {
				heap.Push(minHeap, NodeDist{
					node: tuple[0],
					dist: tuple[1] + nd.dist,
				})
			}
		}
	}
	if len(dist) != N {
		return -1
	}
	max := -1
	for _, d := range dist {
		if d > max {
			max = d
		}
	}
	return max
}

type NodeDist struct {
	node int
	dist int
}

type NodeDistMinHeap []NodeDist

func (pq *NodeDistMinHeap) Len() int {
	return len(*pq)
}
func (pq *NodeDistMinHeap) Less(i, j int) bool {
	return (*pq)[i].dist < (*pq)[j].dist
}
func (pq *NodeDistMinHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *NodeDistMinHeap) Push(x interface{}) {
	*pq = append(*pq, x.(NodeDist))
}

func (pq *NodeDistMinHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}
func (pq *NodeDistMinHeap) Peek() NodeDist {
	return (*pq)[0]
}
```