### 解题思路

使用滑动窗口的思想进行解题

### 代码

```golang
func findContinuousSequence(target int) [][]int {
	i, j := 1, 1
	sum := 0
	idx := 0
	result := make([][]int, 0)

	for i <= target/2 {
		if sum < target {
			sum += j
			j++
		} else if sum > target {
			sum -= i
			i++
		} else {
			result = append(result, make([]int, 0, j-1))
			for k := i; k < j; k++ {
				result[idx] = append(result[idx], k)
			}
			idx++
			sum -= i
			i++
		}
	}

	return result
}
```