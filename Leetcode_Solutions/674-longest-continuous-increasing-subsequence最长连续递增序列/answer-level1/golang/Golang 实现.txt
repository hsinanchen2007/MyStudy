以第 i 个元素为结尾的最长递增子串长度为 l[i]
- 如果 i 比 i-1 元素大，则可继续构建递增子串 l[i] = l[i-1] + 1
- 如果 i 比 i-1 元素小，则只能以 i 为开头构造递增串 l[i] = 1

```
func findLengthOfLCIS(nums []int) int {
    if len(nums) <= 1 {
        return len(nums)
    }
    
    max := 1
    cur := 1

    for i, _ := range nums {
        if i == 0 {
            continue
        }
        if nums[i] > nums[i-1] {
            cur = cur + 1
        } else {
            cur = 1
        }
        if cur > max {
            max = cur
        }
    }
    return max
    
}
```

时间复杂度 O(n)
空间复杂度 O(1)
