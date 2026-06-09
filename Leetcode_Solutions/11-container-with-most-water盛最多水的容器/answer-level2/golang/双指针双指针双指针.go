### 解题思路
此处撰写解题思路

### 代码

```golang
// 自己写的是暴利破解法，更新用双指针法
func maxArea(height []int) int {
    res := 0
    left := 0
    n := len(height)
    right := n - 1
    dis := n - 1
    for left < right && dis > 0 {
        if height[left] <= height[right] {
            tmp := height[left] * dis
            if tmp > res {
                res = tmp
            }
            left++
        } else {
            tmp := height[right] * dis
            if tmp > res {
                res = tmp
            }
            right--
        }
        dis--
    }
    return res
}
```