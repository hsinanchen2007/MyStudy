### 解题思路
- 原地工作，nums[i]表示以下标i结尾的最大的子数组和，max是全局最大和。
- 核心思想：当nums[i-1]大于零时，对后面的子数组和才会起增加的作用，故累加上；否则重新计数。
- 每次算出以下标i结尾的最大的子数组和之后，和全局最大和比较。若大于全局最大和则更新。
### 代码

```golang
//最优解，时间复杂度O(n),空间复杂度O(1)

func maxSubArray(nums []int) int {
    
    l := len(nums)
    max := nums[0]

    for i:=1; i<l; i++ {
        if nums[i-1] >  0 {
            nums[i] += nums[i-1]
        }
        if nums[i] > max {
            max = nums[i]
        }
    }
    return max
}
```