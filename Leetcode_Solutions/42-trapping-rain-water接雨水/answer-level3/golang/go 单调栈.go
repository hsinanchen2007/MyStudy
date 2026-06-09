**几点思想：**
1. 维护单调递减栈，始终保持栈单调性，如果遇到[5,2],要进3，则pop2，变为[5,3]
2. 栈内存的是数组索引！ 需要好好理解下
3. 如果下一个元素比当前栈顶元素小，则直接入栈。否则将所有与栈顶元素相同的元素一起出栈。[5,4,2,2,2]要入3,变为[5,4,3]
4. 出栈结束后，结果+= （min（当前栈顶，新入栈的元素）-刚刚出栈的值） * （入栈元素的索引 - 当前栈顶的索引 -1） （高度*宽度）
5. 计算完成后再将新的入栈元素入栈。
6. 最后用go的切片模拟栈


```
func trap(height []int) int {

	stack := []int{}
	res := 0
	for i := 0 ; i < len(height) ; i ++{

		for len(stack) != 0 && height[stack[len(stack) - 1]] < height[i]{
			curIndex := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			for len(stack) != 0 && height[stack[len(stack)-1]] == height[curIndex]{
				stack = stack[:len(stack)-1]
			}

			if len(stack) != 0 {

				res += (min(height[i], height[stack[len(stack)-1]]) - height[curIndex]) * (i - stack[len(stack)-1] - 1)
			}
		}
		stack = append(stack, i)

	}
	return res
}
func min(a,b int)int{
	if a < b{
		return a
	}else{
		return b
	}
}
```
