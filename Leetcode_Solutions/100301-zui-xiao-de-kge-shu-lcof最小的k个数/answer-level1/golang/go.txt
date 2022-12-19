### 解题思路
此处撰写解题思路

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
	sort.Sort(Array(arr))
	return arr[:k]
}

type Array []int

func (a Array) Len() int           { return len(a) }
func (a Array) Less(i, j int) bool { return a[i] < a[j] }
func (a Array) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
```