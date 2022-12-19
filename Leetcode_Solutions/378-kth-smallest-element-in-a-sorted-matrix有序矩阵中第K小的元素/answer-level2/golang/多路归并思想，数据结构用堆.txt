### 解题思路
本题解来自公众号**算法和数据结构的峡谷**

没想到我用多路归并的方法时间复杂度应该是nlogn 的状态下 比暴力的还慢。。。。。。。。。。。。。。。。。。。。

### 代码

```golang
// 使用堆进行求解，但是维护一个length为k的堆即可。


func kthSmallest4(matrix [][]int, k int) int {
    if len(matrix) ==0 {
        return 0
    }

	heapSpec := new(IntHeapSpec) // 为了实现堆，这里的堆是 [][3]int 这个样子
// 其中这个内部的数组 0 是行index 1是列index 2 是value。

	//init 初始化这个小顶堆。
	for i := 0; i < len(matrix); i++ {

		l := [3]int{
			i, 0, matrix[i][0],
		}

		heapSpec.Push(l)

	}
	// 使用对路归并原理（min(min1,min2,min3)）
	for i := 1; i <= k-1; i++ {

		result := heap.Pop(heapSpec).([3]int)
		if result[0] < len(matrix) && result[1] < len(matrix[0])-1 { // 如果数组用完了就pop了不能再比较了。
			heap.Push(heapSpec, [3]int{result[0], result[1] + 1, matrix[result[0]][result[1]+1]})
		}

	}
	return heapSpec.Top().([3]int)[2]
}

