看了题解，大多都是动态规划、BFS或者四平方，试试下面这个穷举法吧。思路就和人脑做这题的思路一样，先看看一个数行不行，不行再两个，以此类推。

```go []
func numSquares(n int) int {
	maxNo := int(math.Sqrt(float64(n)))
	numbers := make([]int, maxNo)
	for i := maxNo; i > 0; i-- {
		numbers[i-1] = i * i
	}
	steps := 1
	for ; steps < n; steps++ {
		if findComponents(numbers, steps, n, maxNo-1) {
			break
		}
	}
	return steps
}

func findComponents(numbers []int, count int, sum int, index int) bool {
	if count == 1 {
		return binarySearch(numbers, sum, 0, index) >= 0
	}
	for i := index; i >= 0; i-- {
		remain := sum - numbers[i]
		if remain > 0 && findComponents(numbers, count-1, remain, i) {
			return true
		}
	}
	return false
}

//缺少checkRange，实用的时候要补上
func binarySearch(l []int, key int, start int, end int) int {
	low := start
	high := end
	for low <= high {
		mid := (low + high) >> 1
		cmp := l[mid] - key
		if cmp < 0 {
			low = mid + 1
		} else if cmp > 0 {
			high = mid - 1
		} else {
			return mid // key found
		}
	}
	return -(low + 1) // key not found
}
```
