执行用时 : 0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 : 2.4 MB, 在所有 Go 提交中击败了41.24%的用户
第一个循环找到第一个不为目标值的数，第二个循环不断将非目标值的数放到前面。

```
func removeElement(nums []int, val int) int {
    p, q := 0, 1
    n := len(nums)
    if n == 0 {
        return 0
    }
    for ; p < n; p++ {
        if nums[p] != val {
            nums[0], nums[p] = nums[p], nums[0]
            break
        }
    }
    if nums[0] != val {
        p, q = 0, 1
        for ; q < n; q++ {
            if nums[q] != val {
                nums[p+1] = nums[q]
                p++
            }
        }
        return p+1
    } else {
        return 0
    }
}
```
