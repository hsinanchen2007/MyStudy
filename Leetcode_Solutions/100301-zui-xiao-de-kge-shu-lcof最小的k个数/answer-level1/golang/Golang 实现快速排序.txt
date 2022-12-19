### 解题思路
1. 无序数组变有序数组，也以使用sort.Ints函数；
2. 数组切片；

### 代码

```golang

func getLeastNumbers(arr []int, k int) []int {
    length := len(arr)
    if length > 10000 {
        return nil
    }

    if k < 0 || k > length {
        return nil
    }

    QuickSort(arr, 0, len(arr)-1)
    return arr[:k]
}

func QuickSort(nums []int, l, h int) {
	if l >= h {
		return
	}

	pivot := nums[l]
	i, j := l, h
	for i < j {
		for i < j && nums[j] >= pivot {
			j--
		}
		nums[i] = nums[j]
		for i < j && nums[i] <= pivot {
			i++
		}
		nums[j] = nums[i]
	}
	nums[i] = pivot

	QuickSort(nums, l, i-1)
	QuickSort(nums, i+1, h)
}
```