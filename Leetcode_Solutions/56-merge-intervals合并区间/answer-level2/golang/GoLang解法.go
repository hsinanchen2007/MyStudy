```
import (
	"sort"
)

func merge(intervals [][]int) [][]int {
	if len(intervals) <= 1 {
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	var ans [][]int
	ans = append(ans, intervals[0])
	for i := 1; i < len(intervals); i++ {
		var a = len(ans) - 1
		var b = len(ans[a]) - 1
		if ans[a][b] >= intervals[i][0] {
			var j = len(intervals[i]) - 1
			ans[a][b] = max(ans[a][b], intervals[i][j])
		} else {
			ans = append(ans, intervals[i])
		}
	}
	return ans
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

```
