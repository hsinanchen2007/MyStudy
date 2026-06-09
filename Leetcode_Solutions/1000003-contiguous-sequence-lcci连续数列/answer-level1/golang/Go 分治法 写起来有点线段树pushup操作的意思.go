```
func maxSubArray(nums []int) int {
    var div func(l, r int) (int, int, int, int)
    div = func(l, r int) (int, int, int, int) {
        if l > r {
            return 0, 0, 0, 0
        } else if l == r {
            return nums[l], nums[l], nums[l], nums[l]
        } else {
            mid := l + (r-l)>>1
            l0, l1, l2, ls:= div(l, mid)
            r0, r1, r2, rs := div(mid+1, r)
            return max(l0, ls+r0), max(r1, rs+l1), max(l1+r0, max(l2, r2)), ls+rs
        }
    }
    _, _, res, _ := div(0, len(nums)-1)
    return res
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
