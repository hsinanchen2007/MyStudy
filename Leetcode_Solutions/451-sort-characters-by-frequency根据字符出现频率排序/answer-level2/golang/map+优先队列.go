
```go
func frequencySort(s string) string {
	hashMap := make(map[string]int)
	for _, v := range s {
		value := string(v)
		count, ok := hashMap[value]
		if ok {
			hashMap[value] = count + 1
		} else {
			hashMap[value] = 1
		}
	}

	pq := make(PriorityQueue, 0)
	for k, v := range hashMap {
		item := Item{
			Value:    k,
			Priority: v,
		}
		heap.Push(&pq, &item)
	}
	ans := ""
	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Item)
		fmt.Println(item.Priority, "\t", item.Value)
		ans += strings.Repeat(item.Value, item.Priority)
	}
	return ans
}

type Item struct {
	Value    string
	Priority int
	index    int
}
type PriorityQueue []*Item //Item为结构体，值传递，所以要采用指针形式（如果需要进行修改数据的话）

func (p PriorityQueue) Len() int {
	return len(p)
}
func (p PriorityQueue) Less(i, j int) bool {
	return p[i].Priority >= p[j].Priority
}
func (p PriorityQueue) Swap(i, j int) {
	p[i], p[j] = p[j], p[i] //整个数据交换，包括索引
	p[i].index = i          //索引值不交换（代表出堆的顺序）
	p[j].index = j
}
func (p *PriorityQueue) Push(x interface{}) {
	n := len(*p)
	item := x.(*Item)
	item.index = n
	*p = append(*p, item)
}
func (p *PriorityQueue) Pop() interface{} {
	old := *p
	n := len(old)
	item := old[n-1]
	item.index = -1 //已经出堆的数据，索引标注为-1.主要是为了和没有出堆的数据进行区别
	*p = old[:n-1]
	return item
}
func (p *PriorityQueue) Update(item *Item, value string, priority int) {
	//根据传递的参数item来判定修改。（先从堆中找到匹配的 item，并对其进行修改）
	item.Value = value
	item.Priority = priority
	//只起修复作用，不用以下语句，也可完成修改，不过堆没有进行相应的移位变化（堆的修复）
	heap.Fix(p, item.index) //在修改第i个元素后，调用本函数修复堆，比删除第i个元素后插入新元素更有效率。
}
func (p *PriorityQueue) Delete(item *Item) {
	heap.Remove(p, item.index)
}
```