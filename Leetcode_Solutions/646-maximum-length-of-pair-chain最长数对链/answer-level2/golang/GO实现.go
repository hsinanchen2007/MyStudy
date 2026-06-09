### 解题思路
首先对第二个值排序，然后对第一个值排序。如{1, 7}, {2, 3}, {3, 4}, {0, 7}排序完应为{2, 3}, {3, 4}, {0, 7},{1, 7}；
遍历，记录当前保存的最小值为min，pairs[i][0]>min，则min=pairs[i][1]，个数加1,。遍历完成即获取最大数。

### 代码

```golang
type MaxChain [][]int

func (m *MaxChain) Len() int {
	return len(*m)
}

func (m *MaxChain) Less(i, j int) bool {
	if (*m)[i][1] <= (*m)[j][1] {
		return true
	}
	return (*m)[i][1] <= (*m)[j][1] && (*m)[i][0] <= (*m)[j][0]
}

func (m *MaxChain) Swap(i, j int) {
	(*m)[i], (*m)[j] = (*m)[j], (*m)[i]
}

func findLongestChain(pairs [][]int) int {
	var chain MaxChain
	chain = pairs
	sort.Sort(&chain)
	count := 1
	curMin := pairs[0][1]
	for i := 1; i < len(pairs); i++ {
		if chain[i][0] > curMin {
			curMin = chain[i][1]
			count++
		}
	}
	return count
}
```