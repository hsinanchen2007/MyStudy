```golang
// 暴力求解，得到每一个容器，然后求得最大值
func maxArea(height []int) int {
    l := len(height)
    max := 0
    for i:=0;i<l-1;i++ {
        n := 0
        for j:=i;j<l;j++ {
            if max < helper(height[i],height[j],n) {
                max = helper(height[i],height[j],n)
            }
            n++
        }
    }
    return max
}

// 求一个容器可盛水的值
func helper(start,end,n int) int{
    if start > end {
        return end * n
    }else {
        return start * n
    }   
}
```