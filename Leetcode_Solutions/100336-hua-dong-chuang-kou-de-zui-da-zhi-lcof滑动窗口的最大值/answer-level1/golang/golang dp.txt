```
func maxSlidingWindow(nums []int, k int) []int {
    n := len(nums)
    if n == 0 {
        return []int{}
    }
    left, right := make([]int, n), make([]int, n)
    for i := 0; i < n; i++ {
        if i % k == 0 {
            left[i] = nums[i]
        } else {
            left[i] = max(left[i-1], nums[i])
        }
        j := n - i - 1
        if j % k == k - 1 || j == n - 1 {
            right[j] = nums[j]
        } else {
            right[j] = max(right[j+1], nums[j])
        }
    }
    ret := []int{}
    for i := 0; i < n - k + 1; i++ {
        ret = append(ret, max(left[i + k - 1], right[i]))
    }
    return ret
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```
