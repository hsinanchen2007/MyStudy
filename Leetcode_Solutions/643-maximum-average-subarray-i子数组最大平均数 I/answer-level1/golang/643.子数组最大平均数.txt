### 解题思路

遍历数组，计算相邻k个元素的最大值再除以k即可。

### 代码

```golang
func findMaxAverage(nums []int, k int) float64 {
	start,end := 0,k - 1
	max := 0
	for i := 0;i < k;i++ {
		max += nums[i]
	}
	tmp := max
	for {
		if end == len(nums) - 1 {
			break
		}
		start++
		end++
		tmp = tmp - nums[start - 1] + nums[end]
		if tmp > max {
			max = tmp
		}
	}
	return float64(max) / float64(k)
}
```