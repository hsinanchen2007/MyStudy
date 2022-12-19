### 解题思路


### 代码

```golang
func isPossible(nums []int) bool {
	count := make(map[int]int, 0)
	// tail[x]维护以x结尾的长度大于等于3的连续子序列个数
	tail := make(map[int]int, 0)

	for _, num := range nums {
		count[num]++
	}
	for _, num := range nums {
		if count[num] == 0 {
			continue
		} else if tail[num-1] > 0 {
			tail[num]++
			tail[num-1]--
		} else if count[num+1] > 0 && count[num+2] > 0 {
			count[num+1]--
			count[num+2]--
			tail[num+2]++
		} else {
			return false
		}
		count[num]--
	}
	return true
}
```