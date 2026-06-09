### 解题思路 - 数组方法

- 执行用时 :1148 ms, 在所有 Go 提交中击败了5.21%的用户
- 内存消耗 :212.2 MB, 在所有 Go 提交中击败了10.00%的用户

维护一个递增的序列，每次添加一个整数后，我们都把它插入到合适的位置，让序列保持有序。

当要计算中位数时，可以直接通过数组下标访问元素。在O(1)的时间内完成查找。

### 代码

```golang
// 数组版本
type MedianFinder struct {
  data []int
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
  return MedianFinder{}
}

// 这个方法需要遍历一遍数组，因此时间复杂度是O(n)
func (this *MedianFinder) AddNum(num int) {
  idx := len(this.data) - 1 // idx指向序列的最后一个数字
  // 当idx大于等于0并且idx指向的数字大于num时
  for idx >= 0 && this.data[idx] > num {
    idx-- // 不断向前移动idx
  }
  // 退出循环后，把num加入到 idx +1的位置即可
  if 0 == len(this.data) || idx+1 == len(this.data) {
    this.data = append(this.data, num)
  } else {
    tmp := make([]int, len(this.data))
    copy(tmp, this.data)
    tmp = append(tmp[:idx+1], num)
    tmp = append(tmp, this.data[idx+1:]...)
    this.data = tmp
  }
  // this.data[idx+1] = num
}

// Time: O(1)
func (this *MedianFinder) FindMedian() float64 {
  n := len(this.data) // 先把当前序列大小赋值给n方便使用
  // 如果n按位与1等于1，说明序列当前长度是奇数
  if n&1 == 1 {
    // 返回序列中下标为n/2的数字即可
    return float64(this.data[int(n/2)])
  } else { // 否则说明当前序列长度是偶数
    // 取出下标为n/2-1和下标为n/2的数字，求他们的平均数，然后返回即可
    return (float64(this.data[int(n/2-1)]) + float64(this.data[int(n/2)])) / float64(2.0)
  }
}
```

### 解题思路 - 最大堆最小堆方法

- 执行用时 :136 ms, 在所有 Go 提交中击败了35.42%的用户
- 内存消耗 :15.4 MB, 在所有 Go 提交中击败了90.00%的用户

接下来我们来优化一下添加元素的时间复杂度，我们最终的目的是使用这个数据结构求中位数。

而求中位数，并不一定需要维护一个递增有序的序列。

我们可以把数据结构中的整数分成数量相当的两堆，

- 其中一堆中的所有数字都小于等于另一堆中的所有数字，
- 那么较小堆中的最大值，和较大堆中的最小值，
- 就是位于这个序列排序后中间的两个数值，
- 根据序列长度是奇数还是偶数，中位数要么是这两个数字中的一个，要么是这两个数字的平均数。

这样一来，我们就不需要维护一个完全有序的序列，而是要维护两个数量相当的堆，分别提供两个堆的最大值和最小值即可。

因此我们使用堆这个数据结构，来求解这个问题。

### 代码

```golang
// 最大堆和最小堆方法
type MedianFinder struct {
  minHeap MinHeap
  maxHeap MaxHeap
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
  return MedianFinder{}
}

// Time: O(logn)
func (this *MedianFinder) AddNum(num int) {
  // 1. 先把数字加入到最小堆
  heap.Push(&this.minHeap, num)
  // 2. 取出最小堆的堆顶元素加入到最大堆中
  heap.Push(&this.maxHeap, heap.Pop(&this.minHeap))
  // 3. 如果最大堆和最小堆的差值超过1
  if this.maxHeap.Len()-this.minHeap.Len() > 1 {
    // 取出最大堆的堆顶元素加入到最小堆
    heap.Push(&this.minHeap, heap.Pop(&this.maxHeap))
  }
}

// 取堆顶元素时间复杂度是 Time: O(1)
func (this *MedianFinder) FindMedian() float64 {
  // 如果最大堆的大小大于最小堆的大小，说明最大堆中比最小堆中多一个元素
  if this.maxHeap.Len() > this.minHeap.Len() {
    // 说明已有序列长度为奇数，直接返回最大堆的堆顶元素即可
    return float64(this.maxHeap[0])
  } else { // 否则说明最大堆和最小堆中元素数量相等
    // 已有序列长度为偶数，取两个堆的堆顶元素平均数即可
    return (float64(this.maxHeap[0]) + float64(this.minHeap[0]))/2
  }
}

// An MinHeap is a min-heap of ints.
type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
  // Push and Pop use pointer receivers because they modify the slice's length,
  // not just its contents.
  *h = append(*h, x.(int))
}

func (h *MinHeap) Pop() interface{} {
  old := *h
  n := len(old)
  x := old[n-1]
  *h = old[0 : n-1]
  return x
}

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
  // Push and Pop use pointer receivers because they modify the slice's length,
  // not just its contents.
  *h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
  old := *h
  n := len(old)
  x := old[n-1]
  *h = old[0 : n-1]
  return x
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
```