```golang
func maxArea(height []int) int {
    ln := len(height)
    ans,l,r :=0,0,ln-1

    for l < r{
        temp := (r-l) * min(height[l],height[r])
        ans = max(temp,ans)
        if height[l] > height[r]{
            r--
        }else {
            l++
        }
    }
    return ans

}

func max(a,b int)int {
    if a >b {
        return a
    }
    return b
}

func min(a,b int)int {
    if a >b {
        return b
    }
    return a
}

// i j 使用 (j-i) * min(height[j],height[i]) 最大

```