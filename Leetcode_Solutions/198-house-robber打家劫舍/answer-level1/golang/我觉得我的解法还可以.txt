### 解题思路
原地工作，nums[i]表示以i结束时打劫的最大收益
状态转移方程：nums[i] = nums[i] + max{nums[i-2],nums[i-1],...,nums[0]}
为了进一步优化空间，用max来缓存max{nums[i-2],nums[i-1],...,nums[0]}。感觉有点影响代码的可读性。

执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2 MB, 在所有 Go 提交中击败了81.85%的用户
### 代码

```golang
//动态规划解法，时间复杂度O(n),空间复杂度O(1)
func rob(nums []int) int {
    l := len(nums)
    max := 0 //max表示下标从0到i-2的累计最大值

    if l == 0 {
        return 0
    }
    if l == 1 {
        return nums[0]
    }
    
    for i:=1; i<l; i++ {
        nums[i] += max
        if nums[i-1] > max {
            max = nums[i-1] //在下标为i时更新i-1的max，下一轮循环i=i+1,使用的是i-1的max，这样才是正确的（不能连续，避免报警）
        }
    }
    if max > nums[l-1] {
        return max
    }else {
        return nums[l-1]
    }
}
```