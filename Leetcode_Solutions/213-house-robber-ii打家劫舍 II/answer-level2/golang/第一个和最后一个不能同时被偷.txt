### 解题思路
分成两个子问题分别动态规划处理

### 代码

```golang
func rob(nums []int) int {
    // 问题的关键在于第一个和最后一个不能同时被偷
    // 那么最终结果就是两种情况的最大值
    // 1. 不偷第一个
    // 2. 不偷最后一个
    if len(nums) == 0 {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    }
    return max(robSimple(nums[:len(nums) - 1]),  robSimple(nums[1:]))
}

// 简单模式
func robSimple(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    non := 0
    rob := nums[0]

    for i := 1; i < len(nums); i++ {
        tmpNon := max(non, rob)
        tmpRob := nums[i] + non
        non = tmpNon
        rob = tmpRob
    }
    return max(non, rob)
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}
```