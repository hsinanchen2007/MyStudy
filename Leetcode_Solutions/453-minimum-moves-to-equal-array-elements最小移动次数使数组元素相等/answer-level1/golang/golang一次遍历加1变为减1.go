# 思路
首先换个角度理解题目，将数组按顺序表示为高度为nums[i]宽度为1的柱子，每次移动i的含义为除i外的所有柱子高度加1，这样i柱子与其他柱子的相对高度减1，可将移动i理解为将i柱子高度减1，其他柱子不变。于是题目变为，求将所有柱子减少为高度相等的柱子所需移动次数。由于每次都只能减少某根柱子的高度1，所以最少要移动sum(nums[i]-min(nums))次。
在遍历nums的过程中，如果nums[i]大于之前的最小值，则nums[i]-min为需要减少的高度；如果nums[i]小于之前的最小值，则需把前面没有减少的高度i*(min-nums[i])，一次减掉。

# 代码
```golang
func minMoves(nums []int) int {
    min := 1<<31 - 1
    sum := 0
    for i := range nums {
        if nums[i] >= min {
            sum += (nums[i]-min)
        } else {
            sum += i * (min-nums[i])
            min = nums[i]
        }
    }
    return sum
}
```