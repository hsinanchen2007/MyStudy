# 解题思路
```
将costs[i][0] 与 costs[i][1] 的差值的绝对值按从小到大排序
根据新的排序再根据costs[i][0]与costs[i][1]的大小决定航班
```

func twoCitySchedCost(costs [][]int) int {
	// 冒泡排序
	for i := 0; i < len(costs); i++ {
		for j := i + 1; j < len(costs); j++ {
			iv := costs[i][0] - costs[i][1]
			if iv < 0 {
				iv = -iv
			}
			jv := costs[j][0] - costs[j][1]
			if jv < 0 {
				jv = -jv
			}
			if jv > iv {
				costs[i], costs[j] = costs[j], costs[i]
			}
		}
	}

	var total int
	var a int
	var b int
	var half = len(costs) / 2
	for _, item := range costs {
		if (item[0] < item[1] && a < half) || b == half {
			total += item[0]
			a++
		} else {
			total += item[1]
			b++
		}
	}
	return total
}