### 解题思路
先排序，再模拟一遍。

### 代码

```golang
func minSubsequence(nums []int) []int {
    sort.Ints(nums)
    sum := 0
    res := make([]int, 0)
    for _, num := range nums {
        sum += num
    }
    ans := 0
    for i := len(nums)-1; ans <= sum/2; i-- {
        res = append(res, nums[i])
        ans += nums[i]
    }
    return res
}
```