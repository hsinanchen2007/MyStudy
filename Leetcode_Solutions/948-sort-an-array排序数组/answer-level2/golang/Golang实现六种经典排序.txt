```
func sortArray(nums []int) []int {
    return heapSort(nums)
}

//插入排序
func insertSort(nums []int) []int {
    n := len(nums)
    for i := 1; i < n; i++ {
        e := nums[i]
        j := i
        for ; j > 0 && e < nums[j-1]; j-- {
            nums[j] = nums[j-1]
        }
        nums[j] = e
    }
    return nums
}

//辅助其他排序的插入排序
func insertSortRange(nums []int, l, r int) {
    for i := l + 1; i <= r; i++ {
        e := nums[i]
        j := i
        for ; j > l && e < nums[j-1]; j-- {
            nums[j] = nums[j-1]
        }
        nums[j] = e
    }
}

//选择排序
func selectSort(nums []int) []int {
    n := len(nums)
    l, r := 0, n-1
    for l < r {
        minIndex, maxIndex := l, r
        if nums[minIndex] > nums[maxIndex] {
            nums[minIndex], nums[maxIndex] = nums[maxIndex], nums[minIndex]
        }
        for i := l + 1; i < r; i++ {
            if nums[i] < nums[minIndex] {
                minIndex = i
            } else if nums[i] > nums[maxIndex] {
                maxIndex = i
            }
        }
        nums[l], nums[minIndex] = nums[minIndex], nums[l]
        nums[r], nums[maxIndex] = nums[maxIndex], nums[r]
        l++
        r--
    }
    return nums
}

func quickSortHelper(nums []int, l, r int) []int {
    if r - l <= 15 {
        insertSortRange(nums, l, r)
        return nums
    }
    randIndex := rand.Intn(r-l+1) + l
    nums[l], nums[randIndex] = nums[randIndex], nums[l]
    lt, rt, i := l, r+1, l+1
    v := nums[l]
    for i < rt {
        if nums[i] < v {
            lt++
            nums[lt], nums[i] = nums[i], nums[lt]
            i++
        } else if nums[i] > v {
            rt--
            nums[rt], nums[i] = nums[i], nums[rt]
        } else {
            i++
        }
    }
    nums[l], nums[lt] = nums[lt], nums[l]
    quickSortHelper(nums, l, lt-1)
    quickSortHelper(nums, rt, r)
    return nums
}

//三路快排
func quickSort(nums []int) []int {
    rand.Seed(time.Now().Unix())
    return quickSortHelper(nums, 0, len(nums)-1)
}

func merge(nums []int, l, m, r int) {
    auk := make([]int, r - l + 1)
    i, j := l, m+1
    k := 0
    for ; k < r - l + 1; k++ {
        if i > m {
            auk[k] = nums[j]
            j++
        } else if j > r {
            auk[k] = nums[i]
            i++
        } else if nums[i] < nums[j] {
            auk[k] = nums[i]
            i++
        } else {
            auk[k] = nums[j]
            j++
        }
    }
    copy(nums[l:r+1], auk)
}

func mergeSortHelper(nums []int, l, r int) {
    if r - l <= 15 {
        insertSortRange(nums, l, r)
        return
    }
    m := l + (r - l) / 2
    mergeSortHelper(nums, l, m)
    mergeSortHelper(nums, m+1, r)
    if nums[m] > nums[m+1] {
        merge(nums, l, m, r)
    }
}

//归并排序
func mergeSort(nums []int) []int {
    mergeSortHelper(nums, 0, len(nums)-1)
    return nums
}

func shiftDown( arr []int, n, k int )  {
	e := arr[k]
	for 2*k+1 < n {
		j := 2*k+1
		if j + 1 < n && arr[j] < arr[j+1] {
			j = j + 1
		}
		if e >= arr[j] {
			break
		}
		arr[k] = arr[j]
		k = j
	}
	arr[k] = e
}

//堆排序
func heapSort( arr []int ) []int {
    n := len(arr)
	for i := (n-1)/2; i >= 0; i-- {
		shiftDown( arr, n, i )
	}

	for i := n-1; i > 0; i-- {
		arr[i], arr[0] = arr[0], arr[i]
		shiftDown( arr, i, 0 )
	}
    return arr
}

```
