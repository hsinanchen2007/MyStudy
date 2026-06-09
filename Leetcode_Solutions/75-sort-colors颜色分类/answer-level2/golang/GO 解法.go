![image.png](https://pic.leetcode-cn.com/bfd61d76baae6e9c1c4393b60598820a727b5480717918ad0ecb13df02e4f3c9-image.png)

### 代码

```golang
func sortColors(nums []int) {
    l := len(nums)
    i, i0, i2 := 0, -1, l

    for i < i2 {
        if nums[i] == 2 {
            nums[i], nums[i2 - 1] = nums[i2 - 1], nums[i]
            i2--
        }

        if nums[i] == 0 {
            nums[i], nums[i0 + 1] = nums[i0 + 1], nums[i]
            i0++
        }

        if nums[i] != 2 {
            i++
        }
    }
}
```