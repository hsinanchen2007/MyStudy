### 解题思路
模拟路径，当需要边缘或在之前走过的点的时候，方向就顺时针旋转一下。

### 代码

```golang
func spiralOrder(matrix [][]int) []int {
  var rdata []int
	c := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	
	whiched := make(map[[2]int]int)
	
	var l int = 0
	var w int = 0
	l = len(matrix)
	if l == 0 {
		return rdata
	}
	
	w = len(matrix[0])
	
	
	var ci int = 0
	var li int = 0
	var wi int = 0
	for len(whiched) < l * w {
		nli := li + c[ci][0]
		nwi := wi + c[ci][1]
		_, ok := whiched[[2]int{nli, nwi}]

		// 四种需要顺时针旋转的情况
		if ok || (nwi == w && nli == 0) || (nwi == w -1 && nli == l) || (nli == l -1 && nwi == -1) {
			ci += 1
			if ci > 3 {
				ci = 0
			}
		}
		
		whiched[[2]int{li, wi}] = 1
		rdata = append(rdata, matrix[li][wi])
		
		cc := c[ci]
		li += cc[0]
		wi += cc[1]
	}
	
	return rdata
}
```