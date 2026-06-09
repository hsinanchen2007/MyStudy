### 解题思路
执行用时 8 ms, 在所有 Go 提交中击败了 96.61% 的用户
内存消耗 4.2 MB, 在所有 Go 提交中击败了 66.67% 的用户

### 代码

```golang
func canJump(nums []int) bool {
    step := len(nums)
    for i:=len(nums); i > 0; i-- {
        if nums[i-1] + i >= step  {
            step = i            
        } 
    }
    return step == 1
}
```