### 解题思路
直接对area开根号就是最近的L，W，但得到的可能不是整数，所以要寻找最近的一对整数解

### 代码

```golang
func constructRectangle(area int) []int {
	w := int(math.Sqrt(float64(area)))
	for area%w != 0 {
		w--
	}
	return []int{area / w, w}
}

```