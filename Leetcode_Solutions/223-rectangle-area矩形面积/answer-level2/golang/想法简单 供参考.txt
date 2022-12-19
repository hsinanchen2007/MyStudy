直接贴代码
```
func computeArea(A int, B int, C int, D int, E int, F int, G int, H int) int {
	//当一个矩形的左下角比另一矩形的右上角横竖坐标都小  而且 此矩形的右上角坐标比另一矩形的左下角坐标都大  有重叠
	if !(A < G && B < H && E < C && F < D) { 
		return (C-A)*(D-B) + (G-E)*(H-F)
	}

	x1 := math.Max(float64(A), float64(E))
	y1 := math.Max(float64(B), float64(F))
	x2 := math.Min(float64(C), float64(G))
	y2 := math.Min(float64(D), float64(H))
	return (C-A)*(D-B) + (G-E)*(H-F) - int((x2-x1)*(y2-y1))
}

```

