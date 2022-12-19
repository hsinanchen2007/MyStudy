因为题目限定了A[i]的大小，所以我猜测应该是想让我们桶排序
```
func sortArray(nums []int) []int {
    s := [100001]int{}
    for i := 0; i < len(nums); i++ {
        s[nums[i] + 50000]++
    }
    idx := 0
    for i := 0; i < 100001; i++ {
        for s[i] > 0 {
            nums[idx] = i - 50000
            idx++
            s[i]--
        }
    }
    return nums
}
```