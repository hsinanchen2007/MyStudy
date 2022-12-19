# 思考
学习自[五分钟学算法](https://mp.***/s/BAaWR6L8XD-2tLhErUXRmA) 

## 最小堆
题目最终需要返回的是前k个频率最大的元素，可以想到借助堆这种数据结构，对于k频率之后的元素不用再去处理

操作为：

- 借助哈希表来建立数字和其出现次数的映射，遍历一遍数组统计元素的频率
- 维护一个元素数目为k的最小堆
- 每次都将新的元素与堆顶元素(堆中频率 最小的元素)进行比较
- 如果新的元素的频率比堆顶端的元素大，则弹出堆顶端的元素，将新的元素添加进堆中
- 最终，堆中的k个元素即为前k个高频元素

## Go实现

### 使用最小堆
错误的示例，结果是随机的

```go
package main

import (
	"container/heap"
	"fmt"
)

func topKFrequent(nums []int, k int) []int {
	// 使用字典，统计每个元素出现的次数，元素为键，元素出现的次数为值
	hashMap := make(map[int]int, len(nums))
	for _, num := range nums {
		hashMap[num]++
	}
	// 遍历map，用最小堆保存频率最大的k个元素
	var h IntHeap
	heap.Init(&h)

	for key, v := range hashMap {
		if h.Len() < k {
			heap.Push(&h, key)
		} else if v > hashMap[h[0]] {
			//heap.Pop(&h)
			//heap.Push(&h, key)
			heap.Fix(&h, key)
		}
	}
	// 取出最小堆中的元素
	var res []int
	for h.Len() > 0 {
		tmp := heap.Pop(&h).(int)
		res = append(res, tmp)
	}
	return res
}
func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	k := 2
	fmt.Println(topKFrequent(nums, k))
}

type IntHeap []int

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
```

### 使用PriorityQueu

```go
package main

import (
	"container/heap"
	"fmt"
	"strconv"
)

func topKFrequent(nums []int, k int) []int {
	// 使用字典，统计每个元素出现的次数，元素为键，元素出现的次数为值
	hashMap := make(map[int]int, len(nums))
	for _, num := range nums {
		hashMap[num]++
	}
	// 遍历map，用最小堆保存频率最大的k个元素
	h := make(PriorityQueue, 0)
	//i := 0
	heap.Init(&h)

	for value, priority := range hashMap {
		if h.Len() < k {
			heap.Push(&h, &Item{
				value:    strconv.Itoa(value),
				priority: priority,
				//index:    i,
			})
		} else if priority > h[0].priority {
			heap.Pop(&h)
			heap.Push(&h, &Item{
				value:    strconv.Itoa(value),
				priority: priority,
				//index:    i,
			})
		}
	}
	// 取出最小堆中的元素
	var res []int
	for h.Len() > 0 {
		tmp := heap.Pop(&h).(*Item).value
		tmp1, _ := strconv.Atoi(tmp)
		res = append(res, tmp1)
	}
	return res
}
func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	k := 2
	fmt.Println(topKFrequent(nums, k))
}

// An Item is something we manage in a priority queue.
type Item struct {
	value    string // The value of the item; arbitrary.
	priority int    // The priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface methods.
	//index int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority < pq[j].priority // 注意这里是需要修改的
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	//pq[i].index = i
	//pq[j].index = j
}
func (pq *PriorityQueue) Push(x interface{}) {
	//n := len(*pq)
	item := x.(*Item)
	//item.index = n
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	//item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

//// update modifies the priority and value of an Item in the queue.
//func (pq *PriorityQueue) update(item *Item, value string, priority int) {
//	item.value = value
//	item.priority = priority
//	heap.Fix(pq, item.index)
//}
```

### 复杂度分析

- 时间复杂度：O(nlogK)，n表示数组的长度。
  - 首先，遍历一遍数组统计元素的频率，这一系列操作的时间复杂度是O(n)；
  - 接着，遍历用于存储元素频率的map，如果元素的频率大于最小堆中顶部的元素，则将顶部的元素删除并将该元素加入堆中，**这里维护堆的数目是k。**
  - 所以这一系列操作的时间复杂度是O(nlogK)
- 空间复杂度：O(n)，最坏情况下（每个元素都不同），map需要存储n个键值对，优先队列需要存储k个元素。

## 桶排序法

- 首先依旧使用哈希表统计频率，统计完成后。
- 创建一个数组，将频率作为数组下标，对于出现频率不同的数字集合，存入对应的数组下标即可。

学习自[aQuaYi](https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0347.top-k-frequent-elements/top-k-frequent-elements.go)

```go
func topKFrequent(nums []int, k int) []int {
	res := make([]int, 0, k)
	// 统计每个数字出现的次数
	rec := make(map[int]int, len(nums))
	for _, n := range nums {
		rec[n]++
	}
	// 对出现次数进行排序
	counts := make([]int, 0, len(rec))
	for _, c := range rec {
		counts = append(counts, c)
	}
	sort.Ints(counts)
	// min是前k个高频数字的底线
	min := counts[len(counts)-k]
	// 收集所有不低于底线的数字
	for n, c := range rec {
		if c >= min {
			res = append(res, n)
		}
	}
	return res
}
```

### 复杂度分析

- 时间复杂度：O(n)，n表示数组的长度。
  - 首先，遍历一遍数组统计元素的频率，这一系列操作的时间复杂度是O(n)
  - 桶的数量为n+1，所以桶排序的时间复杂度是O(n)
- 空间复杂度：O(n)。