这道题一个坑就是对输入没有说明，所以需要自己对输入进行处理和规整。

```
import "sort"

func merge(intervals [][]int) (rst [][]int) {
	if len(intervals) < 2 {
		return intervals
	}

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	for i := 0; i < len(intervals)-1; i++ {
		curr := intervals[i]
		if curr[0] <= intervals[i+1][0] &&
			curr[1] >= intervals[i+1][0] {
			intervals[i+1][0] = curr[0]
			if intervals[i+1][1] < curr[1] {
				intervals[i+1][1] = curr[1]
			}
		} else {
			rst = append(rst, curr)
		}
	}

	rst = append(rst, intervals[len(intervals)-1])
	return
}

```
