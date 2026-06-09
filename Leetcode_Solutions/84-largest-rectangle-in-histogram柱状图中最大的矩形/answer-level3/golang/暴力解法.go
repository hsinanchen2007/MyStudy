
暴力1 
时间复杂度 n^3 (运行超时)
第一遍 ：找到左边界
第二便 ：找到右边界
第三遍 ：找到左右边界面积最大的情况

```
func largestRectangleArea(heights []int) int {
    l := len(heights)
    max:= 0 
    for i:= 0; i < l; i++ {
        for j:= i; j < l; j++{
            minHeigh := heights[i]
            for  k:=i; k<=j;k++{
                if heights[k] <  minHeigh{
                    minHeigh = heights[k]
                }
            }
            if tmp := minHeigh*(j-i+1) ; tmp > max {
                max = tmp
            }
        }
    }  
    return max
}

```

暴力2 
第一遍 找到基准柱子
第二遍 和其他柱子的面积的所有组合，并找到最大max

```
func largestRectangleArea(heights []int) int {
    maxArea := 0 
    for i:=0; i < len(heights); i++ {
        minHeight := heights[i]
        for j:= i; j < len(heights); j++ { 
            if minHeight > heights[j] {
                minHeight = heights[j]
            }
            if tmp := minHeight * (j-i+1); tmp > maxArea {
                maxArea = tmp
            }
        }
    }
    return maxArea
}
```

