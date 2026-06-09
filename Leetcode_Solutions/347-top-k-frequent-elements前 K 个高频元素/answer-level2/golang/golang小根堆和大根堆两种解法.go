方法1：使用小根堆, 先用map统计词频, 然后放到小根堆里面, 但是要优于O(N * logN),
       所以, 小根堆只开辟k个大小, 这样小根堆中push和pop时时间复杂度就是O(logk)
```
/*
    执行用时 : 16 ms, 在所有 Go 提交中击败了82.08%的用户
    内存消耗 :5.5 MB, 在所有 Go 提交中击败了73.95%的用户
*/
func topKFrequent(nums []int, k int) []int {
	if k == 0 || len(nums) == 0 {
		return make([]int, 0)
	}
	// 1. 初始化map
	m := make(map[int]int)
	for _, v := range nums {
		m[v] = m[v] + 1
	}

	// 2. 放到小根堆里面
	h := &NodeHeap{}
	topK := min(k, len(m))
	size := 0
	for k, v := range m {
		if size < topK {
			heap.Push(h, &Node{
				val:   k,
				times: v,
			})
			size++
		} else {
			if v > (*h)[0].times {
				heap.Pop(h)
				heap.Push(h, &Node{
					val:   k,
					times: v,
				})
			}
		}

	}

	// 3.收集答案
	res := make([]int, 0, topK)
	for i := 0; i < topK; i++ {
		res = append(res, heap.Pop(h).(*Node).val)
	}
	return res
}

type Node struct {
	val   int
	times int
}

type NodeHeap []*Node

func (h NodeHeap) Len() int { return len(h) }

// 小根堆
func (h NodeHeap) Less(i, j int) bool { return h[i].times < h[j].times }

func (h NodeHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *NodeHeap) Push(x interface{}) {
	*h = append(*h, x.(*Node))
}

func (h *NodeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```
方法2：使用大根堆, 在map统计完词频后, 放到切片中, 然后用heap.init方法(该方法原理是从底向上建堆, 时间复杂度是O(N), N是切片的长度, 也就是统计词频表map的长度), 然后pop, 一共弹出topk次, 所以该种解法的时间复杂度是O(topk * logn)
```
func topKFrequent(nums []int, k int) []int {
	if k == 0 || len(nums) == 0 {
		return make([]int, 0)
	}
	m := make(map[int]int)
	for _, v := range nums {
		m[v] = m[v] + 1
	}
	nodes := make(NodeHeap, 0, len(m))
	for k, v := range m {
		nodes = append(nodes, &Node{
			val:   k,
			times: v,
		})
	}
	h := &nodes
	heap.Init(h)
	topK := min(k, len(m))
	res := make([]int, 0, topK)
	for i := 0; i < topK; i++ {
		res = append(res, heap.Pop(h).(*Node).val)
	}
	return res
}

type Node struct {
	val   int
	times int
}

type NodeHeap []*Node

func (h NodeHeap) Len() int { return len(h) }

// 大根堆
func (h NodeHeap) Less(i, j int) bool { return h[i].times > h[j].times }

func (h NodeHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *NodeHeap) Push(x interface{}) {
	*h = append(*h, x.(*Node))
}

func (h *NodeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```
