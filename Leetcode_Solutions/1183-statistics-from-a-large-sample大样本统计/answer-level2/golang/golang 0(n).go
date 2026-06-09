第一遍循环可以找出最大值，最小值，众数，总数和总量。
通过总数和总量可以求出平均值，那么还有最后一个众数。

通过总量的奇偶性，计算出众数在第几个位置。如果是偶数，有两个众数，即cnt/2, cnt/2 + 1。如果是奇数，只有一个 cnt/2 + 1，为了方便，我们设置为两个相同的数。

第二遍遍历，找到众数，所有需要的数都已经找到。

```
if cnt%2 == 0 {
	mid1, mid2 = cnt/2, cnt/2 + 1
} else {
	mid1, mid2 = cnt/2 + 1, cnt/2 + 1
}
```

```
func sampleStats(count []int) []float64 {
	var min, max, sum, most, mostCount, cnt int
	min = -1
	for i := 0; i < len(count); i++ {
		if count[i] == 0 {
			continue
		}
		sum = sum + count[i] * i
		cnt += count[i]
		if count[i] > mostCount {
			most = i
			mostCount = count[i]
		}
		if min == -1 {
			min = i
		}
		max = i
	}
	avg := float64(sum)/float64(cnt)
	var mid1, mid2 int
	if cnt%2 == 0 {
		mid1, mid2 = cnt/2, cnt/2 + 1
	} else {
		mid1, mid2 = cnt/2 + 1, cnt/2 + 1
	}
	mid := 0
	for i := 0; i < len(count); i++ {
		if count[i] == 0 {
			continue
		}
		mid1 -= count[i]
		mid2 -= count[i]
		if mid1 <= 0 {
			mid += i
			mid1 = 2 << 31
		}
		if mid2 <= 0 {
			mid += i
			break
		}
	}
	return []float64{float64(min), float64(max), avg, float64(mid)/float64(2), float64(most)}
}

```
