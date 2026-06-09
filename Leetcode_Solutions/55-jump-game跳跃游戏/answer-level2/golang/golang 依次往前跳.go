### 解题思路

解题思路参考这位同学的妙思：
https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/

执行用时 :8 ms, 在所有 Go 提交中击败了97.03%的用户
内存消耗 :4.2 MB, 在所有 Go 提交中击败了63.49%的用户

### 代码

```golang

func canJump(nums []int) bool {
    maxPosition := 0
    for i,num := range nums {
        if i > maxPosition {
            return false
        }
        maxPosition = max(maxPosition, i+num)
    }
    return true
}
func max(a,b int) int {
    if a > b {
        return a
    }else{
        return b
    }
}
```