### 解题思路
此处撰写解题思路

### 代码

```golang
func sortArray(nums []int) []int {
    // 1.1 选择排序, O(n^2) 超时  
    // BenchmarkSeledt1-6   	       1	2278185134 ns/op	      16 B/op	       2 allocs/op
    // for i:=0; i< len(nums)-1;i++ {
    //     minIdx := i
    //     for j := i+1; j < len(nums); j++ {
    //         if nums[minIdx] > nums[j] {
    //             minIdx = j
    //         }
    //     }
    //     nums[minIdx], nums[i] = nums[i], nums[minIdx]
    // }
    // return nums
    //
    // 1.2 选择排序，优雅写法 O(n^2) 超时
    // BenchmarkSeledt2-6   	       1	6101282795 ns/op	       8 B/op	       1 allocs/op
    // for i:=0; i< len(nums)-1; i++ {
    //     for j := i+1; j < len(nums); j++ {
    //         if nums[i] > nums[j] {
    //             nums[j], nums[i] = nums[i], nums[j]
    //         }
    //     }
    // }
    // return nums
    //
    // 2.1 插入排序, O(n^2)  304ms
    // BenchmarkInsert1-6   	   17367	     68484 ns/op	       0 B/op	       0 allocs/op
    // for i:=1; i<len(nums); i++ {
    //     tmp := nums[i]
    //     j := i 
    //     for j > 0 && tmp < nums[j-1] {
    //         nums[j] = nums[j-1]
    //         j--
    //     }
    //     nums[j] = tmp
    // }
    // return nums
    //
    // 2.2 插入排序，优雅写法 O(n^2)  976ms
    // BenchmarkInsert2-6   	       1	1619086496 ns/op	      16 B/op	       2 allocs/op
    // for i := range nums {
	// 	for i > 0 && nums[i] < nums[i-1] {
	// 		nums[i], nums[i-1] = nums[i-1], nums[i]
	// 		i--
	// 	}
	// }
	// return nums
    //
    // 3 冒泡排序 O(n^2) 超时
    // BenchmarkMaoPao-6   	       1	5764915436 ns/op	      16 B/op	       2 allocs/op
    // for i := 0; i < len(nums); i++ {
	// 	for j := 1; j < len(nums)-i; j++ {
	// 		if nums[j-1] > nums[j] {
	// 			nums[j-1], nums[j] = nums[j], nums[j-1]
	// 		}
	// 	}
	// }
	// return nums
    //
    // 4 快排 O(nlogn) 20ms
    // BenchmarkQuickSort-6   	     100	  21078276 ns/op	       0 B/op	       0 allocs/op
    // quick(0, len(nums)-1, nums)
    // return nums
    //
    // 5 合并 O(n^2) 28ms
    // BenchmarkMergeSort-6   	     109	  10731306 ns/op	 6751752 B/op	   49999 allocs/op
    // if len(nums) <= 1 {
    //     return nums
    // }
    // left, right := nums[0:len(nums)/2], nums[len(nums)/2:]
    // left = sortArray(left)
    // right = sortArray(right)
    // return merge(left, right)
    // 
    // 6 堆排序
    // 

    // build head
	// n := len(nums)
	// for i := n / 2; i >= 0; i-- {
	// 	headify(nums, i, n)
	// }
	// sort and rebuild head
	// for i := n - 1; i >= 0; i-- {
	// 	nums[0], nums[i] = nums[i], nums[0]
	// 	headify(nums, 0, i)
	// }
	// return nums
    // 7 标准库 28ms
    sort.Ints(nums)
    return nums
}

func partation(nums []int, lo, hi int) int {
	for j := lo; j < hi; j++ {
		if nums[lo] < nums[hi] {
			nums[lo], nums[j] = nums[j], nums[lo]
			lo++
		}
	}
	nums[lo], nums[hi] = nums[hi], nums[lo]
	return lo
}

func quick(nums []int, left, right int) {
	if left > right {
		return
	}
	p := partation(nums, left, right)
	quick(nums, left, p-1)
	quick(nums, p+1, right)
}

func merge(left, right []int) []int {
	arr := make([]int, len(left)+len(right))
	var l, r int
	for i := 0; i < len(arr); i++ {
		if l >= len(left) {
			copy(arr[i:], right[r:])
			break
		} else if r >= len(right) {
			copy(arr[i:], left[l:])
			break
		}
		if left[l] < right[r] {
			arr[i] = left[l]
			l++
		} else {
			arr[i] = right[r]
			r++
		}
	}
	return arr
}

func headify(nums []int, pos, endPos int) {
	newItem := nums[pos]
	childPos := pos*2 + 1
	for childPos < endPos {
		rightPos := childPos + 1
		if rightPos < endPos && nums[childPos] < nums[rightPos] {
			childPos = rightPos
		}
		if newItem < nums[childPos] {
			nums[pos], nums[childPos] = nums[childPos], nums[pos]
			pos = childPos
			childPos = pos*2 + 1
		} else {
			break
		}
	}
	nums[pos] = newItem
}

```