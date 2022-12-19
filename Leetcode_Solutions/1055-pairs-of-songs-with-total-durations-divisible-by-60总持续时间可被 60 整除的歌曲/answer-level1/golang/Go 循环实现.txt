将每个数值对60取余保存在数组中，当前数组元素对60取余后，同余数数组中下标相加等于60的计数总和即为结果。
```
执行用时 : 40 ms, 在Pairs of Songs With Total Durations Divisible by 60的Go提交中击败了100.00% 的用户
内存消耗 : 6.3 MB, 在Pairs of Songs With Total Durations Divisible by 60的Go提交中击败了72.41% 的用户
```
```Go []
func numPairsDivisibleBy60(time []int) int {
	m := make([]int, 60)
	cnt := 0
	for _, n := range time {
		if n%60 == 0 {
			cnt += m[0]
		} else {
			cnt += m[60-n%60]
		}
		m[n%60]++
	}
	return cnt
}