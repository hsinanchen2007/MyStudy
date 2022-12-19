### 解题思路
利用go自带的heap实现很简单。

### 代码

```golang
type IntHeap []int

func (h IntHeap) Len() int{
    return len(h)
}

func (h IntHeap) Less (i, j int) bool {
    return h[i] > h[j]
}

func (h IntHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
    num := (*h)[len((*h)) - 1]
    *h = (*h)[:len(*h) - 1]
    return num
}

func getLeastNumbers(arr []int, k int) []int {
    intHeap := IntHeap{}
    intHeap = append(intHeap, arr[0:k]...)
    if len(intHeap) == 0 {
        return intHeap
    }
    
    heap.Init(&intHeap)

    for i := k ; i < len(arr); i++ {
        if arr[i] < intHeap[0] {
            heap.Pop(&intHeap)
            heap.Push(&intHeap, arr[i])
        }
    }
    return intHeap
}
```