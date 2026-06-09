### 解题思路
go sort包内置排序

### 代码

```golang
func sortArray(nums []int) []int {
    Sort(nums)
    return nums
}

func insertionSort(data []int, a, b int) {
	for i := a + 1; i < b; i++ {
		for j := i; j > a && Less(data, j, j-1); j-- {
			Swap(data, j, j-1)
		}
	}
}

func siftDown(data []int, lo, hi, first int) {
	root := lo
	for {
		child := 2*root + 1
		if child >= hi {
			break
		}
		if child+1 < hi && Less(data, first+child, first+child+1) {
			child++
		}
		if !Less(data, first+root, first+child) {
			return
		}
		Swap(data, first+root, first+child)
		root = child
	}
}

func heapSort(data []int, a, b int) {
	first := a
	lo := 0
	hi := b - a

	for i := (hi - 1) / 2; i >= 0; i-- {
		siftDown(data, i, hi, first)
	}

	for i := hi - 1; i >= 0; i-- {
		Swap(data, first, first+i)
		siftDown(data, lo, i, first)
	}
}

func medianOfThree(data []int, m1, m0, m2 int) {
	if Less(data, m1, m0) {
		Swap(data, m1, m0)
	}
	if Less(data, m2, m1) {
		Swap(data, m2, m1)
		if Less(data, m1, m0) {
			Swap(data, m1, m0)
		}
	}
}

func doPivot(data []int, lo, hi int) (midlo, midhi int) {
	m := int(uint(lo+hi) >> 1)
	if hi-lo > 40 {
		s := (hi - lo) / 8
		medianOfThree(data, lo, lo+s, lo+2*s)
		medianOfThree(data, m, m-s, m+s)
		medianOfThree(data, hi-1, hi-1-s, hi-1-2*s)
	}
	medianOfThree(data, lo, m, hi-1)

	pivot := lo
	a, c := lo+1, hi-1

	for ; a < c && Less(data, a, pivot); a++ {
	}
	b := a
	for {
		for ; b < c && !Less(data, pivot, b); b++ {
		}
		for ; b < c && Less(data, pivot, c-1); c-- {
		}
		if b >= c {
			break
		}
		Swap(data, b, c-1)
		b++
		c--
	}
	protect := hi-c < 5
	if !protect && hi-c < (hi-lo)/4 {
		dups := 0
		if !Less(data, pivot, hi-1) {
			Swap(data, c, hi-1)
			c++
			dups++
		}
		if !Less(data, b-1, pivot) {
			b--
			dups++
		}
		
		if !Less(data, m, pivot) {
			Swap(data, m, b-1)
			b--
			dups++
		}

		protect = dups > 1
	}
	if protect {

		for {
			for ; a < b && !Less(data, b-1, pivot); b-- {
			}
			for ; a < b && Less(data, a, pivot); a++ {
			}
			if a >= b {
				break
			}

			Swap(data, a, b-1)
			a++
			b--
		}
	}

	Swap(data, pivot, b-1)
	return b - 1, c
}

func quickSort(data []int, a, b, maxDepth int) {
	for b-a > 12 {
		if maxDepth == 0 {
			heapSort(data, a, b)
			return
		}
		maxDepth--
		mlo, mhi := doPivot(data, a, b)

		if mlo-a < b-mhi {
			quickSort(data, a, mlo, maxDepth)
			a = mhi
		} else {
			quickSort(data, mhi, b, maxDepth)
			b = mlo
		}
	}
	if b-a > 1 {

		for i := a + 6; i < b; i++ {
			if Less(data, i, i-6) {
				Swap(data, i, i-6)
			}
		}
		insertionSort(data, a, b)
	}
}

func Sort(data []int) {
	n := len(data)
	quickSort(data, 0, n, maxDepth(n))
}

func maxDepth(n int) int {
	var depth int
	for i := n; i > 0; i >>= 1 {
		depth++
	}
	return depth * 2
}

func Less(data []int, i int, j int) bool {
	if data[i] < data[j] {
		return true
	}
	return false
}

func Swap(data []int, i int, j int) {
	data[i], data[j] = data[j], data[i]
}

```