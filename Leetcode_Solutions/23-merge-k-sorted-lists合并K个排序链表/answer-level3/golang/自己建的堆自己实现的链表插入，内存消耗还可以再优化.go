### 解题思路
1.将链表中的数据建堆
2.对堆进行排序
3.将堆中数据插入到新的链表中

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 
func mergeKLists(lists []*ListNode) *ListNode {
    // 创建堆
    heap := NewHeap()
    for _, list := range lists {
        // 遍历每个链表，将数据插入到堆中
        for nil != list {
            heap.insert(list.Val)
            list = list.Next
        }
    }
    heap.sort()
    // 根据堆数组，创建一个新链表
    var list *ListNode
    for i := len(heap.a) - 1; i>0; i-- {
        list = insertToHead(list, heap.a[i])
    }
    return list
}

// 向链表头部插入
func insertToHead(list *ListNode, val int) *ListNode {
	newNode := &ListNode{
		Val: val,
	}
	if list == nil {
		return newNode
	}
	newNode.Next = list
	return newNode
}

// 堆结构
type Heap struct {
	a []int // 堆数组，存放数据
	n int   // 堆大小
}

// 获取父节点索引
func parent(k int) int {
	return k / 2
}

// 获取左子树节点
func left(k int) int {
	return k * 2
}

// 获取右子树节点
func right(k int) int {
	return k * 2 + 1
}

// 比较两个节点
func (this *Heap) less(node1 int, node2 int) bool {
	return this.a[node1] < this.a[node2]
}

// 创建堆结构，0不保存数据
func NewHeap() *Heap {
	return &Heap{
		a: make([]int, 1),
		n: 1,
	}
}

// 上浮第 n 个节点
func (this *Heap) swim(k int) {
	// 当 k == 1时候不能再上浮了
	for k > 1 && this.less(parent(k), k) {
		// 父节点小于子节点，交换数据
		this.a[parent(k)], this.a[k] = this.a[k], this.a[parent(k)]
		k = parent(k)
	}
}

// 下沉第 n 个数据
func (this *Heap) sink(k int) {
	// 左子树是否存在
	for left(k) < this.n {
		old := left(k)
		// 判断右子树是否存在并与左子树值比较,如果右子树值大于左子树则覆盖old
		if right(k) < this.n && this.less(old, right(k)) {
			old = right(k)
		}
		// 父节点大于左右子树
		if this.less(old, k) {
			break
		}
		// 交换值
		this.a[k], this.a[old] = this.a[old], this.a[k]
		k = old
	}
}
// 下沉第k个到n数据
func (this *Heap) sinkTo(k int, n int) {
	// 左子树是否存在
	for left(k) <= n {
		old := left(k)
		// 判断右子树是否存在并与左子树值比较,如果右子树值大于左子树则覆盖old
		if right(k) <= n && this.less(old, right(k)) {
			old = right(k)
		}
		// 父节点大于左右子树
		if this.less(old, k) {
			break
		}
		// 交换值
		this.a[k], this.a[old] = this.a[old], this.a[k]
		k = old
	}
}

// 下沉第k个到n数据
// func (this *Heap) heapify(n int, i int) {
// 	for true {
// 		maxPos := i
// 		if left(i) <= n && this.less(i, left(i)) {
// 			maxPos = i * 2
// 		}
// 		if right(i) <= n && this.less(maxPos, right(i)) {
// 			maxPos = i * 2 + 1
// 		}
// 		if maxPos == i {
// 			break
// 		}
// 		this.a[i], this.a[maxPos] = this.a[maxPos], this.a[i]
// 		i = maxPos
// 	}
// }

// 在堆末尾插入一个数据
func (this *Heap) insert(val int) {
	// 将数据加入到数组中
	this.a = append(this.a, val)
	// 数组长度+1
	this.n++
	// 上浮这个新数据
	this.swim(this.n - 1)
}

// 堆排序
func (this *Heap) sort() {
	N := this.n - 1
	for N > 1 {
		// 堆顶与末尾交换
		this.a[N], this.a[1] = this.a[1], this.a[N]
		N--
		// 下沉堆顶数据
		// this.heapify(N, 1)
		this.sinkTo(1, N)
	}
}
```