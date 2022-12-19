二分查找混合遍历，最坏情况下遍历

没有重复项的话，此题比较好解，可直接二分查找
重复项影响到的情况是初始数组为[2,1,2,2,2]的情况

采取的方法是，判断 arr[mid]，arr[left]，arr[right]相等时，左右都向 mid 移动一位，即下一层继续查找 [1,2,2] 数组，最坏情况为[2,2,1,2,2]，将会遍历整个数组

```
func search(arr []int, target int) int {
    // 取巧，只可能发生在最开始的数组中
    if arr[0] == target {
        return 0
    }
    return dfs(arr, target, 0, len(arr)-1)
}

func dfs(arr []int, target, left, right int) int {
	if left > right {
		return -1
	}

	mid := (left + right) >> 1
	for ; arr[mid] == target; mid-- {
		if arr[mid-1] != target {
			return mid
		}
	}

	if left == right {
		return -1
	}

    // 取巧，只可能发生在最开始的数组中，两边减1，递归处理
    if arr[mid] == arr[left] && arr[mid] == arr[right] {
        return dfs(arr, target, left+1, right-1)
    }

	if arr[mid] > target && (arr[left] > arr[mid] || arr[left] <= target) || (arr[right] < target && arr[left] > arr[mid]) {
		return dfs(arr, target, left, mid)
	}

	return dfs(arr, target, mid+1, right)
}


```
