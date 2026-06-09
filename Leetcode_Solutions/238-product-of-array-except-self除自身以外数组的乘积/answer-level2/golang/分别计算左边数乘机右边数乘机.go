### 解题思路
此处撰写解题思路

### 代码

```golang
func productExceptSelf(nums []int) []int {
    // 用一个数组存结果
    var res []int
    res = append(res, 1)
    for i := 1; i < len(nums); i++ {
        // 计算左边乘机
        res = append(res, res[i - 1] * nums[i - 1])
    }
    // 计算右边
    R := 1
    for i := len(nums) - 1; i >= 0; i-- {
        tmp := res[i] * R
        res[i] = tmp
        R = R * nums[i]
    }
    return res 
}
```