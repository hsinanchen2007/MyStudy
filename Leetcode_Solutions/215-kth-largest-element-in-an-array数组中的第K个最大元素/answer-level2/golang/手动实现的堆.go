### 解题思路
1. 对给定的数据建立堆
2. 删除堆顶数据，因为要找第k大元素所以要执行(k-1)次

### 代码

```golang
// 基本思路
// 1.建堆
// 2.排序生成一个数组f
// 3.返回f(k)
func findKthLargest(nums []int, k int) int {
    // 建堆
    heap := NewHeap()
    for _, v := range nums {
        heap.insert(v)
    }
    for i := 0; i<k-1; i++ {
        heap.delMax()
    }
    return heap.a[1]
}

// 堆结构
type Heap struct {
    a []int // 存放数据
    n int   // 堆大小
}

// 创建堆
func NewHeap() *Heap {
    return &Heap{
        a: make([]int, 1),
        n: 1,
    }
}

// 获取父节点索引
func parent(root int) int {
    return root / 2
}

// 获取root节点左子树索引
func left(root int) int {
    return root * 2
}

// 获取root节点右子树索引
func right(root int) int {
    return root * 2 + 1
}

// 判断一个节点是否小于另一个节点
func (this *Heap) less(n1 int, n2 int) bool {
    return this.a[n1] < this.a[n2]
}

// 上浮第n个数据
func (this *Heap) swim(n int) {
    // 父节点小于当前节点，当前节点需要上浮
    for n > 1 && this.less(parent(n), n) {
        this.a[parent(n)], this.a[n] = this.a[n], this.a[parent(n)]
        n = parent(n)
    }
}

// 插入一个数据
func (this *Heap) insert(val int) {
    // 插入到数组
    this.a = append(this.a, val)
    this.n++
    this.swim(this.n - 1)
}

// 下沉第k个数据
func (this *Heap) sink(k int) {
    // 保证左子树存在
    for left(k) < this.n {
        old := left(k)
        // 判断右子树是否存在并与左子树比较大小
        if right(k) < this.n && this.less(old, right(k)) {
            old = right(k)
        }
        // 与k比较大小
        if this.a[k] > this.a[old] {
            break
        }
        // 交换数据
        this.a[k], this.a[old] = this.a[old], this.a[k]
        k = old
    }
}

func (this *Heap) delMax() {
    // 将最小的值赋值给最大值
    this.a[1] = this.a[this.n-1]
    this.n--
    // 下沉
    this.sink(1)
}







```