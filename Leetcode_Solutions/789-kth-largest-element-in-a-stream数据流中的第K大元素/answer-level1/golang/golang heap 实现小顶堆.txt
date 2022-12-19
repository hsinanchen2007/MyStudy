type KthLargest struct {
    minH IntHeap
    k int
}


func Constructor(k int, nums []int) KthLargest {
    var v KthLargest
    v.minH = make(IntHeap, 0, k)
    v.k = k
    heap.Init(&v.minH)
    for i:=0; i<k&&i<len(nums);i++{
        heap.Push(&v.minH, nums[i])
    }
    for i:=k;i< len(nums);i++{
        if nums[i] > v.minH[0] {
            v.minH[0] = nums[i]
            heap.Fix(&v.minH, 0)
        }
    }
    
    return v
}


func (this *KthLargest) Add(val int) int {
    if this.minH.Len() < this.k {
        heap.Push(&this.minH, val)
    } else {
        if val > this.minH[0] {
            this.minH[0] = val
            heap.Fix(&this.minH, 0)
        }
    }

    return this.minH[0]
}

type IntHeap []int
func (h IntHeap) Len() int {return len(h)}
func (h IntHeap) Less(i, j int) bool {return h[i]<h[j]}
func (h IntHeap) Swap(i, j int) {h[i], h[j] = h[j], h[i]}
func (h *IntHeap) Push(x interface{}) {*h = append(*h, x.(int))}
func (h *IntHeap) Pop() interface{} {old := *h;n := len(old);x := old[n-1];*h = old[:n-1];return x}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */