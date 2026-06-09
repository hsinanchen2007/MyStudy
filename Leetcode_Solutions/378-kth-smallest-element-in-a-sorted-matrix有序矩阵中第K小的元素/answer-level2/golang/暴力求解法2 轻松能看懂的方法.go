### 解题思路
本题解来自 微信公众号：**算法和数据结构的峡谷**

本算法 不香，时间复杂度和空间复杂度都很大。
但是也是一种方法 记录一下，但是看懂很容易啊，这也算优点吧。我的
### 代码

```golang
// 暴力求解  将数据放入堆中，然后取出第k个。 时间复杂度 nm + nmlognm + 每次堆化的时间 总之很垃圾。
func kthSmallest(matrix [][]int, k int) int {
   he := &IntHeap{}// 初始化一个堆
    for i := 0; i < len(matrix);i++ {
        for j := 0;j < len(matrix[i]);j++ {
             heap.Push(he,matrix[i][j]) // 一股脑将所有数据传入这个堆中
        }
    }
    var result interface{}
    for i := 0;i < k; i++ {
        result = heap.Pop(he) // 然后将这个小顶堆（go自己实现的就是小顶堆）顶端popk次就OK了。
    }
    return result.(int)

}



// 下面这一堆东西主要是为了实现go的堆的接口 --- 为了实现堆，所以各位不用看。

type IntHeap []int
func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) {
   
    *h = append(*h, x.(int))
}
func (h *IntHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

```