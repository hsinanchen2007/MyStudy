### 解题思路
1、对pairs排序, 优先对比第一个元素，若第一个元素相等，则对比最后一个元素
2、设置对链中最小值为maxInt， 倒序遍历pairs，若元素最后一个元素小于对链中的最小值，对链数量+1，对链最小值设置为元素第一个元素

### 代码

```golang
func findLongestChain(pairs [][]int) int {
    arr := Pairs{}
	arr = pairs
	sort.Sort(arr)

	cnt, max := 0, 1<<31-1

	for i := len(arr) - 1; i >= 0; i-- {
		if arr[i][len(arr[i]) - 1] < max {
			max = arr[i][0]
			cnt++
		}
	}

	return cnt
}

type Pairs [][]int

func (p Pairs) Len() int {
	return len(p)
}

func (p Pairs) Less(i, j int) bool {
	if p[i][0] < p[j][0] {
		return true
	}
	if p[i][0] == p[j][0] && p[i][len(p[i])-1] < p[j][len(p[j])-1] {
		return true
	}
	return false
}

func (p Pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}
```