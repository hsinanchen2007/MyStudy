### 解题思路
pq注意优先级相同使用字典序 

### 代码

```golang

func topKFrequent(words []string, k int) []string {
	m := make(map[string]int)
	for i := 0; i < len(words); i++ {
		if v, ok := m[words[i]]; ok {
			m[words[i]] = v + 1
		} else {
			m[words[i]] = 1
		}
	}

	pq := make(priorityQueue, 0)
	heap.Init(&pq)
	for key, value := range m {
		heap.Push(&pq, &item{
			priority: value,
			value:    key,
		})
		if pq.Len() > k {
			heap.Pop(&pq)
		}
	}

	r := make([]string, k)
	for k > 0 {
		r[k-1] = heap.Pop(&pq).(*item).value
		k--
	}
	return r
}

type item struct {
	priority int
	value    string
}
type priorityQueue []*item

func (p priorityQueue) Len() int {
	return len(p)
}

func (p priorityQueue) Less(i, j int) bool {
	if p[i].priority < p[j].priority {
		return true
	}
	if p[i].priority == p[j].priority {
		return p[i].value > p[j].value
	}
	return false
}

func (p priorityQueue) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p *priorityQueue) Push(x interface{}) {
	*p = append(*p, x.(*item))
}

func (p *priorityQueue) Pop() interface{} {
	length := p.Len()
	v := (*p)[length-1]
	*p = (*p)[:length-1]
	return v
}

```