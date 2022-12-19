最理想的情况是柱子形成一个　凹　型，即两边的柱子高度大于任何一个中间柱子，这样直接计算两个柱子围成的容积，再减去中间柱子占的空间，即可．

1. 首先确定两个柱子之间是否有更高者或者至少高于等于两边柱子其中一个的柱子，转2，若没有，转3
2. 分成两部分后继续，每部分各自进行第１步
3. 两个柱子之间的容量减去中间其他柱子所占据的体积

```
func trap(height []int) int {
    if len(height) <= 2 {
        return 0
    }
    return divide_trap(height,0,len(height)-1)
}

func divide_trap(height []int, left int, right int) int {
    var index int
    if height[left] > height[right] {
        index = right
    }else {
        index = left
    }
    for i := left+1; i< right; i++ {
        if height[i] > height[index] {
            index = i
        }
    }
    if index == left || index == right {
        var inter int
        for i :=left+1;i < right; i++ {
            inter += height[i]
        }
        if height[left] > height[right] {
            return (right - left -1) * height[right] -inter
        }else {
            return (right - left -1) * height[left] - inter
        }
    }else {
        var sum int 
        if index - left > 1 {
            sum += divide_trap(height,left,index)
        }
        if right - index > 1 {
            sum += divide_trap(height,index,right)
    }
}
```
