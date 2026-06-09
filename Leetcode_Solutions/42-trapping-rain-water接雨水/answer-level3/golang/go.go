### 解题思路
此处撰写解题思路

### 代码

```golang
func trap(height []int) int {
    left := []int{}
    right := []int{}
    h := 0
    for i := 0;i < len(height); i++{
        left = append(left,h)
        if height[i] > h{
            h = height[i]
        }
    }

    h = 0
    for i := len(height)-1;i >=0; i--{
        right = append([]int{h},right...)
        if height[i] > h{
            h = height[i]
        }
    }
    res := 0
    for x:= range height{
        res += max(0,min(left[x],right[x])-height[x])
    }
    return res
}

func min(a,b int) int{
    if a> b{
        return b
    }
    return a
}

func max(a,b int) int{
    if a> b{
        return a
    }
    return b
}
```