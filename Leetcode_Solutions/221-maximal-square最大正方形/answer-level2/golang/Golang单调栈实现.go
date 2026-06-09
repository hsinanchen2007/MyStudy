#提供一个思路，使用单调栈实现（同84，85题）
```
//单调栈实现
func maximalSquare(matrix [][]byte) int {
    if matrix==nil || len(matrix)==0{
        return 0
    }
    res:=0
    height:=make([]int,len(matrix[0]))
    for i:=0;i<len(matrix);i++{
        for j:=0;j<len(matrix[0]);j++{
            if matrix[i][j]=='1'{
                height[j]++
            }else{
                height[j]=0
            }
        }
        res=int(math.Max(float64(res),float64(maxSquare(height))))
    }
    return res
    
}
//单调栈实现(与最大矩形类似)
func maxSquare(heights []int)int{
    maxarea:=0
    stack:=make([]int,0)
    stack=append(stack,-1)
    for i:=0;i<len(heights);i++{
        for stack[len(stack)-1]!=-1 && heights[stack[len(stack)-1]]>=heights[i]{
            tmp:=stack[len(stack)-1]
            stack=stack[:len(stack)-1]
            //宽度
            w:=i-stack[len(stack)-1]-1
            //当宽度>=高度时，才能构成正方形
            if w>=heights[tmp]{
                maxarea=int(math.Max(float64(maxarea),float64(heights[tmp]*heights[tmp])))
            }
        }
        stack=append(stack,i)
    }
    for stack[len(stack)-1]!=-1{
        //暂存栈顶元素的值
        tmp:=stack[len(stack)-1]
        //出栈
        stack=stack[:len(stack)-1]
        //宽度
        w:=len(heights)-stack[len(stack)-1]-1
        if w>=heights[tmp]{
            maxarea=int(math.Max(float64(maxarea),float64(heights[tmp]*heights[tmp])))
        }
    }
    return maxarea
}
```
