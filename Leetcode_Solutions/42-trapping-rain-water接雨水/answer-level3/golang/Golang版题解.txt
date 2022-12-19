```
func trap(height []int) int {
    var res, lm, rm int
    left, right := 0, len(height)-1
    for left<=right {
        lm = int(math.Max(float64(height[left]), float64(lm)))
        rm = int(math.Max(float64(height[right]), float64(rm)))
        if lm < rm {
            res += lm - height[left]
            left++
            continue
        }

        res += rm - height[right]
        right--
    }

    return res
}
```