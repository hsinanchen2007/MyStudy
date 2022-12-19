# 排序

- 最朴素的方法是先对数组进行排序，再返回倒数第 k 个元素，就像 Python 中的 sorted(nums)[-k]。
- 算法的时间复杂度为O(NlogN)，空间复杂度为O(1)。
- 这个时间复杂度并不令人满意，让我们试着用额外空间来优化时间复杂度。
```go
func findKthLargest(nums []int, k int) int {
  sort.Slice(nums, func(i, j int) bool {
    return nums[i] > nums[j]
  })
  return nums[k-1]
}
```
# 快排
```go 
func findKthLargest(nums []int, k int) int {
  return solved(nums, 0, len(nums)-1, len(nums)-k)
}

// partition过程,和快排的partition一样
func partition(arr []int, l, r int) int {
  // p := rand.Int()%(r-l+1) + l
  // arr[l], arr[p] = arr[p], arr[l]

  j := l // [l+1...j]<p; [lt...i]>p
  for i := l + 1; i <= r; i++ {
    if arr[i] < arr[l] {
      j++
      arr[i], arr[j] = arr[j], arr[i]
    }
  }
  arr[l], arr[j] = arr[j], arr[l]
  return j
}

// 求出arr[l...r]范围里第k小的数
func solved(arr []int, l, r, k int) int {
  if l == r {
    return arr[l]
  }
  // partition之后,arr[p]的正确位置就在索引p上
  p := partition(arr, l, r)
  if k == p { // 如果k==p,直接返回arr[p]
    return arr[p]
  } else if k < p { // 如果k<p,只需要在arr[l...p-1]中找出第k小的元素即可
    return solved(arr, l, p-1, k)
  } else { // 如果k>p,则需要在arr[p+1...r]中找出第k-p-1小的元素
    // 注意: 由于传入solved的依然是arr,而不是arr[p+1...r]
    // 所以传入的最后一个参数依然是k,而不是k-p-1
    return solved(arr, p+1, r, k)
  }
}
```
# 最小堆
```go
// Using Min Heap to store the k largest elements
// Time Complexity: O(nlogk) Space Complexity: O(k)
// https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0215.kth-largest-element-in-an-array/kth-largest-element-in-an-array.go
func findKthLargest2(nums []int, k int) int {
  temp := highHeap(nums)
  h := &temp
  heap.Init(h)
  if k == 1 {
    return (*h)[0]
  }
  for i := 1; i < k; i++ {
    heap.Remove(h, 0)
  }
  return (*h)[0]
}

// highHeap 实现了Heap 的接口
type highHeap []int

func (h highHeap) Len() int            { return len(h) }
func (h highHeap) Less(i, j int) bool  { return h[i] > h[j] } // h[i] > h[j] 使得 h[0] == max(h...)
func (h highHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *highHeap) Push(x interface{}) { *h = append(*h, x.(int)) } // Push 使用 *h，是因为增加了 h 的长度
func (h *highHeap) Pop() interface{} { // Pop 使用 *h，是因为减短了 h 的长度
  res := (*h)[len(*h)-1]
  *h = (*h)[:len(*h)-1]
  return res
}
```

#快排思想
```go
// Based on Quick Sort Partition.Time Complexity: O(n) Space Complexity: O(logn)
func findKthLargest3(nums []int, k int) int {
  rand.Seed(time.Now().Unix())
  return _findKthLargest(nums, 0, len(nums)-1, k-1)
}

func _findKthLargest(nums []int, l, r, k int) int {
  if l == r {
    return nums[l]
  }
  p := partition(nums, l, r)
  if p == k {
    return nums[p]
  } else if k < p {
    return _findKthLargest(nums, l, p-1, k)
  } else { // k>p
    return _findKthLargest(nums, p+1, r, k)
  }
}

func partition(nums []int, l, r int) int {
  p := rand.Int()%(r-l+1) + l
  nums[l], nums[p] = nums[p], nums[l]

  lt := l + 1 // [l+1...lt) > p; [lt...i) < p
  for i := l + 1; i <= r; i++ {
    if nums[i] > nums[l] {
      nums[i], nums[lt] = nums[lt], nums[i]
      lt++
    }
  }
  nums[l], nums[lt-1] = nums[lt-1], nums[l]
  return lt - 1
}
```