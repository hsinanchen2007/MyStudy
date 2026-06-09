### 解题思路
 1.用堆来记录两块石头粉碎后的值
 2.用堆尾的石头继续与新的石头粉碎，将粉碎后的结果插入到堆中
 3.将新数据上浮
 4.执行到最后，

### 代码

```golang
// 思路：
// 1.用堆来记录两块石头粉碎后的值
// 2.用堆尾的石头继续与新的石头粉碎，将粉碎后的结果插入到堆中
// 3.将新数据上浮
// 4.执行到最后，
func lastStoneWeight(stones []int) int {
    // 生成堆
    heap := NewHeap()
    // 构造堆
    for _, v := range stones {
        heap.insert(v)
    }

    for heap.n > 2 {
        n1 := heap.delMax()
        n2 := heap.delMax()
        if n1 != n2 {
            heap.insert(int(math.Abs(float64(n1 - n2))))
        }
    }
    if heap.n == 2 {
        return heap.a[1]
    }
    return 0
}
/**************************** 手写一个大顶堆 ****************************/
// 堆结构体
type Heap struct {
    a []int // 用于存放堆数据的数组
    n int   // 堆大小
}

// 生成堆
func NewHeap() *Heap {
    return &Heap{
        a: make([]int, 1),
        n: 1,
    }
}

// 获取节点的父节点索引
func parent(root int) int {
    return root / 2
}

// 获取节点左子树索引
func left(root int) int {
    return root * 2
}

// 获取节点右子树索引
func right(root int) int {
    return root * 2 + 1
}

// 判断一个节点是否小于另外一个节点
func (this *Heap) less(root1 int, root2 int) bool {
    return this.a[root1] < this.a[root2]
}

// 插入堆元素
func (this *Heap) insert(val int) {
    // 将元素加入到数组中
    this.a = append(this.a, val)
    // 堆长度增加
    this.n++
    // 上浮该元素
    this.swim(this.n - 1)
}

// 上浮第n个数据
func (this *Heap) swim(k int) {
    // 只要没有上浮到第一个节点就继续上浮
    for k > 1 && this.less(parent(k), k) {
        // 如果父节点小于子节点，交换数据
        this.a[parent(k)], this.a[k] = this.a[k], this.a[parent(k)]
        k = parent(k)
    }
}

// 下沉第n个节点
func (this *Heap) sink(k int) {
    // 先从节点左子树开始
    for left(k) < this.n {
        old := left(k)
        // 比较右子树与左子树的大小
        if right(k) < this.n && this.less(old, right(k)) {
            // 右子树大于左子树，右子树值覆盖左子树
            old = right(k)
        }
        // 当前节点与左右子树比较
        if this.less(old, k) {
            // 左右子树都小于父节点，结束循环
            break
        }
        // 交换值
        this.a[old], this.a[k] = this.a[k], this.a[old]
        k = old
    }
}

func (this *Heap) delMax() int {
    var res int
    N := this.n - 1
    res = this.a[1]
    // 最小值赋给堆顶元素
    this.a[1] = this.a[N]
    this.n--
    this.a = this.a[:this.n]
    // 下沉
    this.sink(1)
    return res
}













```