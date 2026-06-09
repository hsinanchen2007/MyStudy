```go
import "container/heap"

type KthLargest struct {
	k int
	heap intHeap
}

func Constructor(k int, nums []int) KthLargest {
	h := intHeap(nums) // 类型转换 数组2heap
	heap.Init(&h) // 构建小顶堆

	// 结构体内部维护一个容量为k的小顶堆
	// 多余的元素都pop出去
	for len(h) > k {
		// 堆pop会将顶元素和最后一个交换
		// 然后缩小堆的规模
		// slice 缩小规模就是将最后一个元素切出去
		// 为什么呢? 因为堆使用数组(这里是切片)存储,
		// index = 0 和 index = len(h)-1 分别对应最小堆的根(即最小值)和最小根的最后一个值(即最大值)
		// 交换后最小的到最后,切掉;最大的到最顶,重新下沉重新整理堆
		heap.Pop(&h)
	}

	return KthLargest{
		k:    k,
		heap: h,
	}
}


func (this *KthLargest) Add(val int) int {
	heap.Push(&this.heap, val)
	if len(this.heap) > this.k {
		heap.Pop(&this.heap)
	}
	return this.heap[0] // 包含k个元素小顶堆的根的值就是第k大
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */

type intHeap []int

func (h intHeap) Len() int {
	return len(h)
}

func (h intHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h intHeap) Swap(i, j int)  {
	h[i], h[j] = h[j], h[i]
}

func (h *intHeap) Push(x interface{})  {
	// Push 使用 *h，是因为
	// Push 增加了 h 的长度
	*h = append(*h, x.(int))
}

func (h *intHeap) Pop() interface{} {
	res := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return res
}
```
