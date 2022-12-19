### 解题思路
每一个元素都异或，初始用0
### 代码

```golang
func singleNumber(nums []int) int {
    l := len(nums)
    if l == 0 {
        return 0
    }
    if l == 1 {
        return nums[0]
    }
    res := 0
    for i := 0; i < l; i++ {
        res = res ^ nums[i]
    }
    return res
}
```