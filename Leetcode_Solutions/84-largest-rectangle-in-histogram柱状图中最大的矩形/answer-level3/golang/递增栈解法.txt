其实最好理解的还是分治法，写出来也简单，但是面对19999个顺序递增的测试用例真的是没脾气
递增栈的解法很巧妙，但是一般人想不出来，只能是经验了
```
func largestRectangleArea(heights []int) int {
    length := len(heights)
    if length <= 0 {
        return 0
    }
    stack := make([]int, length+1)
    top := 0
    stack[top] = -1
    maxArea := 0
    for i:=0; i<length; i++ {
        if top == 0 || heights[i] >= heights[stack[top]] {
            top++
            stack[top] = i
        } else if heights[i] < heights[stack[top]] {
            for heights[i] < heights[stack[top]] {
                if maxArea < heights[stack[top]] * (i - stack[top-1]-1) {
                    maxArea = heights[stack[top]] * (i - stack[top-1]-1)
                }
                top--
                if top == 0 {
                    break
                }
            }
            top++
			stack[top] = i
        }
    }
    for top != 0 {
        if maxArea < heights[stack[top]] * (length - stack[top-1]-1) {
            maxArea = heights[stack[top]] * (length - stack[top-1]-1)
        }
        top--
    }
    return maxArea
}
```