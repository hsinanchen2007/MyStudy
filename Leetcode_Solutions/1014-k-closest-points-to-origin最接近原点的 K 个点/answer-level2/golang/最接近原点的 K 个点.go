### 解题思路
此处撰写解题思路

### 代码

```golang

func kClosest(points [][]int, K int) [][]int {
	kClosest := getKClosest(points, K)

	return kClosest
}
// getKClosest
func getKClosest(points [][]int, K int) [][]int {
	//revertK := len(points) - K
	quickIndexSelect(points, 0, len(points)-1, K)
	return points[0:K]
}


// quickSelect返回第k个最小的数
func quickIndexSelect(nums [][]int, left, right, kSmallest int) int {
	if left == right {
		return left
	}

	pivot_i := partitionNums(nums, left, right)
	if pivot_i == kSmallest {
		return pivot_i
	} else if pivot_i > kSmallest {
		return quickIndexSelect(nums, left, pivot_i-1, kSmallest)
	} else {
		return quickIndexSelect(nums, pivot_i+1, right, kSmallest)
	}
}

// 分治
func partitionNums(nums [][]int, left, right int) int {
	// 移动哨兵到末端
	pivot := distanceToZeroPoint(nums[left])
	swapNums(nums, left, right)

	// 比较，并交换
	store_i := left
	for left <= right {
		if distanceToZeroPoint(nums[left]) < pivot {
			swapNums(nums, left, store_i)
			store_i++
		}
		left++
	}

	// 放哨兵到最终的位置
	swapNums(nums, store_i, right)
	return store_i
}

// swap交换
func swapNums(nums [][]int, i, j int) {
	tmp := nums[i]
	nums[i] = nums[j]
	nums[j] = tmp
}

// distanceToZeroPoint 某点距离原点的距离
func distanceToZeroPoint(point []int) float64 {
	distance := 0
	for _, v := range point {
		distance = distance + v*v
	}
	return math.Sqrt(float64(distance))
}
```