### 解题思路
Go 官方题解思路

### 代码

```golang
func nextGreaterElements(nums []int) []int {
    stack := make([]int,0)
    res := make([]int, len(nums))
    for i:= 2*len(nums)-1; i>=0 ; i-- {
        for len(stack) >0 && nums[i%len(nums)]>=nums[stack[len(stack)-1]]{
            stack = stack[:len(stack)-1]
        }
        if len(stack)==0 {
            res[i%len(nums)] = -1
        } else {
            res[i%len(nums)] = nums[stack[len(stack)-1]]
        }
        stack = append(stack,i%len(nums))
    }
    return res
}
```