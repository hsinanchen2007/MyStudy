# 解决方案
构造一个优先队列(最大堆)，每次去poll出前两个最重的石头(x, y)，如果x > y, 则往队列中添加(x-y)。重复执行上述操作，直到最后一个石头。
# 代码实现
```
func lastStoneWeight(stones []int) int {
	pq := PriorityQueue{}
	for _, stone := range stones {
		pq.Offer(stone)
	}
	for pq.size() >= 2 {
		x := pq.Poll()
		y := pq.Poll()
		if x > y {
			pq.Offer(x - y)
		}
	}
	if pq.size() == 1 {
		return pq.Peek()
	}
	return 0
}

type PriorityQueue []int

func (pq PriorityQueue) size() int {
	return len(pq)
}

func (pq *PriorityQueue) Poll() int {
	max := pq.Peek()
	pq.swap(0, pq.size()-1)
	*pq = (*pq)[0 : (*pq).size()-1]
	pq.sink(0)
	return max
}

func (pq *PriorityQueue) Offer(value int) {
	*pq = append(*pq, value)
	pq.swim(pq.size() - 1)
}

func (pq PriorityQueue) Peek() int {
	return pq[0]
}

func (pq PriorityQueue) less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PriorityQueue) swap(i, j int) {
	tmp := pq[i]
	pq[i] = pq[j]
	pq[j] = tmp
}

func (pq PriorityQueue) swim(i int) {
	for i > 0 && pq.less(parent(i), i) { // 如果上浮到堆顶，就不能再上浮了
		pq.swap(parent(i), i)
		i = parent(i)
	}
}

func (pq PriorityQueue) sink(i int) {
	for left(i) < pq.size() {
		older := left(i)
		if right(i) < pq.size() && pq.less(older, right(i)) {
			older = right(i)
		}
		if pq.less(older, i) {
			break
		}
		pq.swap(older, i)
		i = older
	}
}

// 父节点的索引
func parent(root int) int {
	return (root - 1) / 2
}

// 左孩子的索引
func left(root int) int {
	return root*2 + 1
}

// 右孩子的索引
func right(root int) int {
	return root*2 + 2
}

```
