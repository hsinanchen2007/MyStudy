### 解题思路
将小时和分钟合并到一个数组，然后回溯遍历，可以加入剪枝条件判断，减少递归的次数
耗时0ms击败100%用户，内存使用2.1 MB，击败27%的用户
### 代码

```golang
func readBinaryWatch(num int) []string {
    if num > 8 {
		return nil
	}
	if num == 0 {
		return []string{"0:00"}
	}

	const timeFormat = "%d:%02d"
	var (
		minNums = []int{1, 2, 4, 8, 16, 32, 1, 2, 4, 8} // 0-5 min 6-9 h
		ans     = make([]string, 0, 10)
	)

	formatTime := func(path []int) string {
		var hourSum, minSum int
		for i := 0; i < len(path); i++ {
			if path[i] >= 0 && path[i] <= 5 {
				minSum += minNums[path[i]]
			} else {
				hourSum += minNums[path[i]]
			}
		}

		return fmt.Sprintf(timeFormat, hourSum, minSum)
	}

	isLegalTime := func(path []int) bool {
		var hourSum, minSum int
		for i := 0; i < len(path); i++ {
			if path[i] >= 0 && path[i] <= 5 {
				minSum += minNums[path[i]]
			} else {
				hourSum += minNums[path[i]]
			}

			if hourSum >= 12 {
				return false
			}
			if minSum >= 60 {
				return false
			}
		}

		return true
	}

	var dfs func(start, reminder int, curPath []int)
	dfs = func(start, reminder int, curPath []int) {
		if reminder == 0 {
			if isLegalTime(curPath) {
				ans = append(ans, formatTime(curPath))
			}
			return
		}

		// 剪枝
		if !isLegalTime(curPath) {
			return
		}

		for i := start; i < len(minNums); i++ {
			curPath = append(curPath, i)
			dfs(i+1, reminder-1, curPath)
			curPath = curPath[:len(curPath)-1]
		}
	}

	dfs(0, num, []int{})

	return ans
}
```