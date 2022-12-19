func largestRectangleArea(heights []int) int {
    // 思路：用栈记录小于当前值的左边的值，遇到右边小于当前值，则弹出求面积，最后取最大面积即可
    // check
    if len(heights) == 0{
        return 0
    }
    stack := make([]int, 0)
    indexs := make([]int, 0)
    results := make([]int, 0)
    // 给末尾添加一个0，用于栈弹出
    heights = append(heights, 0)
    for i := 0; i < len(heights); i++ {
        if len(stack) == 0 {
            stack = append(stack, heights[i])
            indexs = append(indexs, i)
            continue
        }

        for len(stack) != 0 && heights[i] < stack[len(stack)-1] {
            // 弹出栈顶计算面积
            height := stack[len(stack)-1]
            // 最后一个元素
            if len(stack) == 1 {
                results = append(results, height*len(heights))
                break
            }
           
            stack = stack[:len(stack)-1]
            index := indexs[len(indexs)-1]
            indexs = indexs[:len(indexs)-1]
            area := height*(i-index)
            results = append(results, area)
        }     
        if heights[i] == 0 {
            results = append(results, 0)
        }
        stack = append(stack, heights[i])
        indexs = append(indexs, i)
    }
    max := results[0]
    for i := 1; i < len(results); i++ {
        if max < results[i] {
            max = results[i]
        }
    }
    return max
}