### 解题思路
哈希+二分查找 对边界场景增加一些处理

### 代码

```golang

func shortestDistanceColor(colors []int, queries [][]int) []int {
	row := len(queries)
	min := math.MaxInt32
	max := math.MinInt32
	m := make(map[int][]int)
	for i := 0; i < len(colors); i++ {
		if min > colors[i] {
			min = colors[i]
		}
		if max < colors[i] {
			max = colors[i]
		}
		if v, ok := m[colors[i]]; ok {
			m[colors[i]] = append(v, i)
		} else {
			m[colors[i]] = []int{i}
		}
	}
	result := make([]int, 0, row)
	for i := 0; i < row; i++ {
		r := find(colors, queries[i], min, max, m)
		result = append(result, r)
	}

	return result
}

func find(colors []int, q []int, min, max int, m map[int][]int) int {
	srcIndex := q[0]
	dstColor := q[1]

	if dstColor < min || dstColor > max {
		return -1
	}

	v, ok := m[dstColor]
	if !ok || len(v) == 0 {
		return -1
	}

	i := sort.SearchInts(v, srcIndex)
	if i >= len(v) {
		return srcIndex - v[i-1]
	}
	diff1 := v[i] - srcIndex
	if i == 0 {
		return diff1
	}
	diff2 := int(math.Abs(float64(v[i-1] - srcIndex)))
	if diff1 >= diff2 {
		return diff2
	}
	return diff1

}

```