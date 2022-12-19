
思路参考前人~

```
func maxArea(height []int) int {
    var left, right = 0, len(height)-1
    max := 0
    for left < right {
        minH, moveLeft := Min(height[left], height[right], left, right)
        // vol := (right - left)*minH
        if (right - left)*minH > max {
            max = (right - left)*minH
        }
        if moveLeft {
            left++
        } else {
            right--
        }
    }
    return max
}
func Min(a, b, l, r int) (int, bool) {
    if a < b {
        return a, true
    }
    return b, false
}

// 暴力解法
// func maxArea(height []int) int {
//     var max = 0
//     for i := 0; i < len(height); i++ {
//         for j := i+1; j < len(height); j++ {
//             vol := (j - i) * Min(height[i], height[j])
//             if vol > max {
//                 max = vol
//             }
//         }
//     }
//     return max
// }

// func Min(a, b) (int) {
//     if a < b {
//         return a
//     }
//     return b
// }
```

