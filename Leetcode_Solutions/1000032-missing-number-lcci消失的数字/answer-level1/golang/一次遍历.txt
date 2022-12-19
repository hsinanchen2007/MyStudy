### 解题思路
n以内的数字求和（包括n），减去数组内所有数字求和就是缺失的数字。

### 代码

```golang
func missingNumber(nums []int) int {
    res := 0
    for i, num := range nums{
        res += ((i+1)-num)
    }
    return res
}
```