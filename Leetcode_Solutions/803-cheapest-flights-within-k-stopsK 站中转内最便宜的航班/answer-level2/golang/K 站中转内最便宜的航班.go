### 解题思路
最小堆

### 代码

```golang
//	787
func findCheapestPrice(n int, flights [][]int, src int, dst int, K int) int {
	graph := make(map[int][][]int)
	for _, flight := range flights {
		graph[flight[0]] = append(graph[flight[0]], []int{flight[1], flight[2]})
	}
	srcSta := Dist{
		node: src,
		dist: 0,
		step: -1,
	}
	minHeap := &DistMinHeap{}
	heap.Push(minHeap, srcSta)
	dist := make(map[int]Dist)
	for minHeap.Len() > 0 {
		d := heap.Pop(minHeap).(Dist)
        if d.node == dst {
			return d.dist
		}
		//	已经找到最小距离的停止搜索
		if dn, ok := dist[d.node]; ok {
			if dn.dist <= d.dist && dn.step <= d.step{
				continue
			} 
		}
		dist[d.node] = d
		//	超过K个中转站的停止搜索
		if d.step == K {
			continue
		}
		for _, nb := range graph[d.node] {
			if _, ok := dist[nb[0]]; !ok {
				heap.Push(minHeap, Dist{
					node: nb[0],
					dist: d.dist + nb[1],
					step: d.step + 1,
				})
			}
		}
	}
	if _, ok := dist[dst]; !ok {
		return -1
	}
	return dist[dst].dist
}

type Dist struct {
	node int
	dist int
	step int
}

type DistMinHeap []Dist

func (pq *DistMinHeap) Len() int {
	return len(*pq)
}
func (pq *DistMinHeap) Less(i, j int) bool {
	return (*pq)[i].dist < (*pq)[j].dist
}
func (pq *DistMinHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *DistMinHeap) Push(x interface{}) {
	*pq = append(*pq, x.(Dist))
}

func (pq *DistMinHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}

func (pq *DistMinHeap) Peek() Dist {
	return (*pq)[0]
}
```