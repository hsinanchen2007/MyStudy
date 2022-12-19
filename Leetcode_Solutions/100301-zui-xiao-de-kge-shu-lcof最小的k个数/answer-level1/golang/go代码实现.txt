### 解题思路
1、 最大堆 求最小值
2、 最小堆 求最大值

### 代码

```golang
package main

import (
	"container/heap"
	"fmt"
)

type IntMinHeap []int

func (pq *IntMinHeap) Len() int {
	return len(*pq)
}
func (pq *IntMinHeap) Less(i, j int) bool {
	return (*pq)[i] > (*pq)[j]
}
func (pq *IntMinHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *IntMinHeap) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *IntMinHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}
func (pq *IntMinHeap) Peek() int {
	return (*pq)[0]
}

//面试题40. 最小的k个数
func getLeastNumbers(arr []int, k int) []int {
	var res []int
	if k == 0 {
		return res
	}
	var minHeap = &IntMinHeap{}
	heap.Init(minHeap)
	for i := 0; i < len(arr); i++ {

		if minHeap.Len() < k {
			heap.Push(minHeap, arr[i])
		} else if minHeap.Peek() > arr[i] {
			heap.Pop(minHeap)
			heap.Push(minHeap, arr[i])
		}

	}
	for minHeap.Len() != 0 {
		res = append(res, heap.Pop(minHeap).(int))
	}
	return res
}

```