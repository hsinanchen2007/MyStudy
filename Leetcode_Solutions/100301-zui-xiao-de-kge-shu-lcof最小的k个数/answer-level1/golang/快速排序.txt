### 解题思路
1、快速排序
2、空间复杂度为O(1)

### 代码

```golang
func quickSort(arr []int) (ret []int) {
	if len(arr) < 2 {
		return arr
	}

	left, right := 0, len(arr)-1

	pivot := rand.Intn(len(arr)) % len(arr)

	arr[right], arr[pivot] = arr[pivot], arr[right]

	for k, v := range arr {
		if v < arr[right] {
			arr[left], arr[k] = arr[k], arr[left]
			left++
		}
	}

	arr[left], arr[right] = arr[right], arr[left]

	quickSort(arr[:left])
	quickSort(arr[left+1:])

	return arr
}

func getLeastNumbers(arr []int, k int) []int {
    return quickSort(arr)[:k]
}
```