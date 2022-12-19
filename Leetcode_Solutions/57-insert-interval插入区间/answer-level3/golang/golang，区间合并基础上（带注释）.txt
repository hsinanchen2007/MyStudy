![1577434075165.jpg](https://pic.leetcode-cn.com/a07016a06a83eb950564d943ac8d13110036adbee0483f38dad371dd327db791-1577434075165.jpg)


因为已经有上一题的基础，所以思路很容易想，就是先把新区间合并到原区间组里，再进行区间合并及可


```
func insert(intervals [][]int, newInterval []int) [][]int {
	if len(newInterval) == 0 {
		return intervals
	}

	if len(intervals) == 0 {
		return [][]int{newInterval}
	}

	if newInterval[0] > intervals[len(intervals)-1][1] {
		return append(intervals, newInterval)
	}

	// 先将 newInterval 与 intervals 合并
	i := 0
	for ; i < len(intervals); i++ {
		// 如查新区间的头比此区间的尾要大，则新区间一定在此区间之间
		if newInterval[0] > intervals[i][1] {
			continue
		}

		// 如果新区间的头比此区间的尾要小，且尾比此区间头要小，则要插入新区间 [4，6]  [1 2 3 4 5, 3 4 5 6 7]
		if newInterval[1] < intervals[i][0] {
			intervals = append(intervals, []int{})
			copy(intervals[i+1:], intervals[i:])
			intervals[i] = newInterval
			break
		}

		// 否则将新区间合并进来
		intervals[i] = []int{Min(intervals[i][0], newInterval[0]),
			Max(intervals[i][1], newInterval[1])}

		break
	}

	// 将问题转化成 对i 及其后部分进行区间合并，与上题区别在于原区间数组无重叠
	tail := i
	for i = i + 1; i < len(intervals); i++ {
		// 如果 intervals[i]的头大于  intervals[tail]的尾,则将 i及后面的部分对 tail 后的部分进行替换
		if intervals[i][0] > intervals[tail][1] {
			if i != tail+1 {
				copy(intervals[tail+1:], intervals[i:])
			}
			return intervals[:tail+len(intervals)-i]
		}

		intervals[tail] = []int{Min(intervals[tail][0], intervals[i][0]),
			Max(intervals[tail][1], intervals[i][1])}

	}

	return intervals[:tail+1]

}

func Min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

func Max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

```
