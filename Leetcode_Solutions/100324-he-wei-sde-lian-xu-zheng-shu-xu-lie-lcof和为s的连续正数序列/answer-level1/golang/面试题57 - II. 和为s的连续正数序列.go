### 解题思路
1.暴力法(超出时间限制 **!)
2.滑动窗口

### 代码

```golang
func findContinuousSequence(target int) [][]int {
	if target <= 0 {
		return [][]int{}
	}
	i := 1 // 滑动窗口的左边界
	j := 1 // 滑动窗口的右边界

	sum := 0
	result := [][]int{}
	for i <= target/2+1 {
		// 如果总和小于目标值
		if sum < target {
			sum += j
			j++
		} else {
			sum = sum - i
			i++
		}
		if sum == target {
			tmp := []int{}
			for k := i; k < j; k++ {
				tmp = append(tmp, k)
			}
			result = append(result, tmp)
			sum = sum - i
			i++
		}
	}
	return result
}

```