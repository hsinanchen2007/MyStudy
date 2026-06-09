Go优先队列解法
```
// 执行用时 :4 ms, 在所有Go提交中击败了100.00%的用户
// 内存消耗 :4.7 MB, 在所有Go提交中击败了100.00%的用户

type Item struct {
	value    string 
	priority int    
	index    int    
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].priority == pq[j].priority {
		return pq[i].value < pq[j].value
	}
	return pq[i].priority > pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func (pq *PriorityQueue) update(item *Item, value string, priority int) {
	item.value = value
	item.priority = priority
	heap.Fix(pq, item.index)
}

func topKFrequent(words []string, k int) []string {
	timesMap := make(map[string]int, 0)
	for _, word := range words {
		timesMap[word]++
	}
	pq := make(PriorityQueue, len(timesMap))
	i := 0
	for value, priority := range timesMap {
		pq[i] = &Item{
			value:    value,
			priority: priority,
			index:    i,
		}
		i++
	}
	heap.Init(&pq)
	result := make([]string, 0)
	for k > 0 {
		result = append(result, heap.Pop(&pq).(*Item).value)
		k--
	}
	return result
}

```