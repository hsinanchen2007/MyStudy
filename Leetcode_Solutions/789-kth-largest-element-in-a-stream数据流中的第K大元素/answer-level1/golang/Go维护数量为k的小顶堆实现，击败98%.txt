import (
    "sort"
    "container/heap"
)
type MyIntList []int

func (this MyIntList) Len() int {
	return len(this)
}
func (this MyIntList) Less(i, j int) bool {
	return this[i] < this[j]
}
func (this MyIntList) Swap(i, j int) {
	this[i], this[j] = this[j], this[i]
}
func (this *MyIntList) Push(x interface{}) {
	*this = append(*this, x.(int))
}
func (this *MyIntList) Pop() interface{} {
	old := *this
	n := len(old)
	x := old[n-1]
	*this = old[0 : n-1]
	return x
}


type KthLargest struct {
	K        int
	MaxKNums *MyIntList
}


func Constructor(k int, nums []int) KthLargest {
	sort.Sort(MyIntList(nums))
	if len(nums) > k {
		nums = nums[len(nums)-k:]
	}
	MaxKNums := MyIntList(nums)
	heap.Init(&MaxKNums)
	return KthLargest{k, &MaxKNums}

}


func (this KthLargest) Add(val int) int {
	if len(*this.MaxKNums) < this.K {
		heap.Push(this.MaxKNums, val)
		return (*this.MaxKNums)[0]
	}
	if val > (*this.MaxKNums)[0] {
		(*this.MaxKNums)[0] = val
		heap.Fix(this.MaxKNums, 0)
	}
	return (*this.MaxKNums)[0]
}