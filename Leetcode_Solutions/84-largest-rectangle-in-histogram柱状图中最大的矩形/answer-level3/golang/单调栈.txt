### 解题思路
此处撰写解题思路

### 代码

```golang
type point struct {
	value int
	index int
}

func largestRectangleArea(heights []int) int {
	var area int
	var pos int 

  //  if len(heights) == 0{
  //      return 0
  //  }

	stack := make([]point, 0)
	tmp := point{
		-1,
		-1,
	}
	stack = append(stack, tmp)

	for i := 0; i < len(heights); i++ {
		if heights[i] >= stack[len(stack)-1].value {
			tmp := point{
				heights[i],
				i,
			}
			stack = append(stack, tmp)
			//fmt.Printf("i:%v,stack:%v\n", i, stack)
			continue
		}
		//出栈，计算面积
		for len(stack) > 0 && stack[len(stack)-1].value > heights[i] {
			topindex := stack[len(stack)-1].index
			stack = stack[:len(stack)-1]
			begin := stack[len(stack)-1].index
			currArea := (i - begin - 1) * heights[topindex]
			area = max(area, currArea)
			//fmt.Printf("i:%v,area:%v,currarea:%v,topindex:%v,begin:%v\n", i, area, currArea, topindex, begin)
		}
		i--

	}
	pos = len(heights)
	for len(stack) > 1{
		topindex := stack[len(stack)-1].index
		stack = stack[:len(stack)-1]
		begin := stack[len(stack)-1].index
		currArea := (pos - begin - 1) * heights[topindex]
		area = max(area, currArea)
       // fmt.Printf("i:%v,area:%v,currarea:%v,topindex:%v,begin:%v\n", pos, area, currArea, topindex, begin)
	}
	return area
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```