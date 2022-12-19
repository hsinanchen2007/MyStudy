第一种：正向判断，从0开始计算所能到达的最远处；
第二种：反向判断，从len(nums) - 1开始，计算所能到达的最左端。

```go
// 正向判断
func canJump(nums []int) bool {
  if len(nums) <= 1 {return true}
  reach := nums[0]
  for i := 0; i <= reach && i < len(nums); i++ {
    if reach < i + nums[i] {
      reach = i + nums[i]
    }
  }
  return reach >= len(nums) - 1
}

// 反向判断
func canJump(nums []int) bool {
    if len(nums) <= 1 {
        return true
    }
    left := len(nums) - 1
    for i := len(nums) - 2; i >= 0; i-- {
        if i + nums[i] >= left {
            left = i
        }
    }
    return left == 0
}
```

