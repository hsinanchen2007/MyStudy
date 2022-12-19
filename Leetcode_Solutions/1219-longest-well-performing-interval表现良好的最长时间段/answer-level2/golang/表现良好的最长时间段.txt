### 解题思路
前缀和+单调递减栈

### 代码

```golang
func longestWPI(hours []int) int {
	for i, v := range hours {
		if v > 8 {
			hours[i] = 1
		} else {
			hours[i] = -1
		}
	}
	prefixSum := make([]int, len(hours)+1)
	for i, v := range hours {
		prefixSum[i+1] = prefixSum[i] + v
	}
	stack := make([]int, 0)
	for i, v := range prefixSum {
		if len(stack) == 0 || prefixSum[stack[len(stack)-1]] > v {
			stack = append(stack, i)
		}
	}
	wpi := 0
	for i := len(prefixSum) - 1; i > wpi; i-- {
		for len(stack) > 0 && prefixSum[i] > prefixSum[stack[len(stack)-1]] {
			w := i - stack[len(stack)-1]
			if wpi < w {
				wpi = w
			}
			stack = stack[:len(stack)-1]
		}
	}
	return wpi
}

```