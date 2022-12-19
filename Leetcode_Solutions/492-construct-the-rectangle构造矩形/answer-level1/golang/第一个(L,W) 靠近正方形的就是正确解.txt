### [第一个靠近正方形的就是正确解](https://mojotv.cn/go/golang-torrent)
此处撰写解题思路
[](https://mojotv.cn/go/golang-torrent)
### 代码

```golang
func constructRectangle(area int) []int {
	if area == 0 {
		return []int{0, 0}
	}
	a := int(math.Sqrt(float64(area)))
	y := 0
	x := 0
	for i := a; i > 0; i-- {
		if area%i == 0 {
			y = area / i
			x = i
			break
		}
	}
	if y > x {
		return []int{y, x}
	} else {
		return []int{x, y}
	}
}

```