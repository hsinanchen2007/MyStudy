双指针start和end，当[start,end]之和sum等于target，即为需要的正数序列，sum减去start，后移；
小于target时，end后移，sum加上end；大于target时，sum减去start，start后移

```
func findContinuousSequence(target int) [][]int {
	limit := target / 2
	start := 1
	end := 2
	sum := start + end
	ret := make([][]int, 0)
	for start <= limit {
		if sum == target {
			ret = append(ret, gen(start, end))
			sum -= start
			start++
		} else if sum < target {
			end++
			sum += end
		} else {
			sum -= start
			start++
		}
	}
	return ret
}

func gen(start, end int) []int {
	ret := make([]int, 0, end-start+1)
	for i := start; i <= end; i++ {
		ret = append(ret, i)
	}
	return ret
}
```
