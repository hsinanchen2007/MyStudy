### 解题思路
此处撰写解题思路

### 代码

```golang
func kClosest(points [][]int, K int) [][]int {
	pq := make(priorityQueue, 0)
	heap.Init(&pq)

	for i := 0; i < len(points); i++ {
		x, y := points[i][0], points[i][1]
		pri := int64(x*x + y*y)
		heap.Push(&pq, &item{
			priority: pri,
			value:    points[i],
		})
		if pq.Len() > K {
			heap.Pop(&pq)
		}
	}

	r := make([][]int, 0)
	for pq.Len() > 0 {
		v := heap.Pop(&pq).(*item).value
		r = append(r, v)
	}

	return r
}

type item struct {
	priority int64
	value    []int
}

type priorityQueue []*item

func (p priorityQueue) Len() int {
	return len(p)
}

func (p priorityQueue) Less(i, j int) bool {
	return p[i].priority > p[j].priority
}

func (p priorityQueue) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p *priorityQueue) Push(x interface{}) {
	*p = append(*p, x.(*item))
}

func (p *priorityQueue) Pop() interface{} {
	l := p.Len()
	v := (*p)[l-1]
	*p = (*p)[:l-1]
	return v
}

```