# 解决方案
    堆的概念参考如下文章：https://leetcode-cn.com/circle/article/bNtb4J/
创建一个包含k(元素从下标1开始)个元素的最小堆(数组包含k+1个元素)，那么堆顶元素就是第k大的值，每添加一个元素时则与堆顶(堆中最小值)进行比较，如果新增的元素大于堆顶元素则直接忽略该新增值，返回堆顶元素。如果新增的元素小于堆顶元素，则将新增的值赋值给堆顶元素并将堆顶元素执行下沉操作到正确的位置，返回堆顶元素
# 代码实现
```
type KthLargest struct {
	pq      []int
	size    int
	maxSize int
}

func Constructor(k int, nums []int) KthLargest {
	heap := KthLargest{
		size:    0,
		maxSize: k,
		pq:      make([]int, k+1),
	}
	for _, num := range nums {
		heap.Add(num)
	}
	return heap
}

/* 插入元素 e */
func (this *KthLargest) Add(value int) int {
	if this.size < this.maxSize {
		this.size++
		this.pq[this.size] = value
		this.Swim(this.size) //上浮
	} else {
		if this.pq[1] >= value {
			return this.pq[1]
		} else {
			this.pq[1] = value
			this.Sink(1) //下沉
		}
	}
	return this.pq[1]
}

/* 上浮第 k 个元素，以维护最小堆性质 */
func (this *KthLargest) Swim(k int) {
	for k > 1 && this.Less(k, this.Parent(k)) {
		this.Exch(k, this.Parent(k))
		k = this.Parent(k)
	}
}

/* 下沉第 k 个元素，以维护最小堆性质 */
func (this *KthLargest) Sink(k int) {
	for this.Left(k) <= this.maxSize {
		older := this.Left(k)
		if this.Right(k) <= this.maxSize && this.Less(this.Right(k), older) {
			older = this.Right(k)
		}
		if this.Less(k, older) {
			break
		}
		this.Exch(older, k)
		k = older
	}
}

/* 交换数组的两个元素 */
func (this *KthLargest) Exch(i, j int) {
	tmp := this.pq[i]
	this.pq[i] = this.pq[j]
	this.pq[j] = tmp
}

/* pq[i] 是否比 pq[j] 小？ */
func (this *KthLargest) Less(i, j int) bool {
	return this.pq[i] < this.pq[j]
}

// 父节点的索引
func (this *KthLargest) Parent(root int) int {
	return root / 2
}

// 左孩子的索引
func (this *KthLargest) Left(root int) int {
	return root * 2
}

// 右孩子的索引
func (this *KthLargest) Right(root int) int {
	return root*2 + 1
}
```
