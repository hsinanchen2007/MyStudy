### 解题思路

二路快排中，是比较大小，有三种情况：大于、小于、等于
此题只有两种情况：奇数、偶数

判断奇数、偶数使用位运算：
与 1 等于 0，即偶数；
与 1 等于 1，即奇数。
### 代码

```golang
func exchange(nums []int) []int {
    l, r := 0, len(nums)-1
    for l < r {
        if nums[l] & 1 == 0 {
            nums[l], nums[r] = nums[r], nums[l]
            r--
        }else {
            l++
        }
    }
    return nums
}
```