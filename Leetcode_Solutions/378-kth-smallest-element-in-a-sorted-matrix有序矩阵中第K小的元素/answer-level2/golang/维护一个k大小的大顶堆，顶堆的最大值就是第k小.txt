### 解题思路
本题解来自 公众号 **算法和数据结构的峡谷**

貌似 这种写法看起来自己很用心的样子，也没多好的时间复杂度。。。。

### 代码

```golang
// 使用堆进行求解，但是维护一个length为k的堆即可。
func kthSmallest(matrix [][]int, k int) int {
	he := &IntHeapM{}
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			// 

			if he.Len() < k { // 数据不到k就一直增加
				heap.Push(he,matrix[i][j])
			} else { // 否则进行对比，然后开始排出不符合规定的数据即可。
				if he.Top().(int) > matrix[i][j] { // 如果 top（最小值） 都比 某个值大 那么
					heap.Pop(he)
					heap.Push(he,matrix[i][j])
				}
			}
		}
	}
	return he.Top().(int)
}
 // 下面是为了实现heap 不用看了。

type IntHeapM []int

func (h IntHeapM) Len() int           { return len(h) }
func (h IntHeapM) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeapM) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeapM) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *IntHeapM) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
func (h *IntHeapM) Top() interface{} {

	return (*h)[0]
}
```