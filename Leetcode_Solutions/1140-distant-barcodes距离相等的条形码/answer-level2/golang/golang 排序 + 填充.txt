思路很简单。可以用堆，也可以用排序。我这里用的是排序，因为go写排序会更快。

1.定义一个结构体，保存值和出现次数
```
type Node struct {
	val int
	count int
}
```
2.用map把数据转换成[]node, 再根据node.count排序
```
sort.Slice(n, func(i, j int) bool {
		return n[i].count > n[j].count
})
```
3.开始填充，先填充偶数位，再填充奇数位，因为肯定有解，所以两次就填完了
```
for count > 0 {
			ret[start] = val
			start += 2
			count--
                         // 如果需要填充的位置 >=  len(barcodes),说明要开始填充奇数位了
			if start >= len(barcodes) {
				start = 1
			}
}
```

完整代码
```
func rearrangeBarcodes(barcodes []int) []int {
	m := make(map[int]int)
	for i := 0; i < len(barcodes); i++ {
		m[barcodes[i]]++
	}
	n := make([]Node, 0, len(m))
	for k, v := range m {
		n = append(n, Node{k, v})
	}
	sort.Slice(n, func(i, j int) bool {
		return n[i].count > n[j].count
	})
	ret := make([]int, len(barcodes))
	start := 0
	for _, v := range n {
		val, count := v.val, v.count
		for count > 0 {
			ret[start] = val
			start += 2
			count--
			if start >= len(barcodes) {
				start = 1
			}
		}
	}
	return ret
}

type Node struct {
	val int
	count int
}
```