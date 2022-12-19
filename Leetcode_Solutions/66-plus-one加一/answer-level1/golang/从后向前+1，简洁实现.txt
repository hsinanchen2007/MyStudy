### 解题思路
思路：从后向前加1，如果加1后变为10，那么继续对前一个元素加1
最后如果第一个元素也变成了10，就需要 append([]int{1}, digits...)

### 代码

```golang
func plusOne(digits []int) []int {
    if digits == nil {
        return nil
    }
    lastIdx := len(digits)-1
    for lastIdx >= 0 {
        digits[lastIdx]++
        if digits[lastIdx] != 10 {
            return digits
        }
        digits[lastIdx] = 0
        lastIdx--
    }
    return append([]int{1}, digits...)
}
```