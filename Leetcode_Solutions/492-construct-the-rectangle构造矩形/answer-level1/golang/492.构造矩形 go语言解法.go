### 解题思路

太简单，不啰嗦直接上代码。

### 代码

```golang

func constructRectangle(area int) []int {
		l := int(math.Sqrt(float64(area)))
		if l * l == area {
			return []int{l,l}
		}
		for {
			l++
			if area % l == 0 {
				return []int{l,area / l}
			}
		}
}
```