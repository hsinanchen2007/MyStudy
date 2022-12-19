# 解题思路

1. 题目只需要求长度，并不关心具体的子序列，所以可以定义max[i]为以nums[i]结尾的最长子序列长度，direction[i]为以nums[i]结尾的最长子序列的方向(-1:递减，1:递增，0:平)
1. 如果nums[i]>nums[i-1]
    1. 若direction[i-1]为1，意味着nums[i-1]结尾的最长子序列末尾选择nums[i]也是一样的，所以max[i]=max[i-1]
    1. 若direction[i-1]为-1，意味着nums[i-1]结尾的最长子序列加上nums[i]可以构成更长的子序列，所以max[i]=max[i-1]+1
1. 如果nums[i]<nums[i-1]
    1. 若direction[i-1]为1，意味着nums[i-1]结尾的最长子序列末尾加上nums[i]可以构成更长的子序列，所以max[i]=max[i-1]+1
    1. 若direction[i-1]为-1，意味着nums[i-1]结尾的最长子序列末尾选择nums[i]也是一样的，所以max[i]=max[i-1]
1. 如果nums[i]=nums[i-1], 则前面最长子序列的末尾选择nums[i]与nums[i-1]是相同的，所以max[i]=max[i-1]，direction[i]=direction[i-1]
1. 由于max[i]和direction[i]只与i-1的相关，可以只用一个变量保存即可
1. 时间复杂度O(n)，空间复杂度O(1)

# 代码
```go []
func wiggleMaxLength(nums []int) int {
    if len(nums) < 2 {
        return len(nums)
    }
    lastMax := 1
    lastDirection := 0
    for i := 1; i < len(nums); i++ {
        if nums[i] > nums[i-1] {
            if lastDirection <= 0 {
                lastMax++
            }
            lastDirection = 1
        } else if nums[i] < nums[i-1] {
            if lastDirection >= 0 {
                lastMax++
            }
            lastDirection = -1
        }
    }
    return lastMax
}
```
