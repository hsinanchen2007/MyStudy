### 解题思路
此处撰写解题思路

### 代码

```golang

func topKFrequent(nums []int, k int) []int {
	m := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if v, ok := m[nums[i]]; ok {
			m[nums[i]] = v + 1
		} else {
			m[nums[i]] = 1
		}
	}

	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	for key, value := range m {
		heap.Push(&pq, &Item{
			value:    key,
			priority: value,
		})
		if pq.Len() > k {
			heap.Pop(&pq)
		}
	}
	length := pq.Len()
	r := make([]int, length)
	for length > 0 {
		r[length-1] = heap.Pop(&pq).(*Item).value
		length--
	}

	return r
}

type Item struct {
	value    int
	priority int
}

type PriorityQueue []*Item

func (p PriorityQueue) Len() int {
	return len(p)
}

func (p PriorityQueue) Less(i, j int) bool {
	return p[i].priority < p[j].priority
}

func (p PriorityQueue) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p *PriorityQueue) Push(x interface{}) {
	*p = append(*p, x.(*Item))
}

func (p *PriorityQueue) Pop() interface{} {
	length := p.Len()
	r := (*p)[length-1]
	*p = (*p)[:length-1]
	return r
}

```