![WX20190611-195017@2x.png](https://pic.leetcode-cn.com/628575b41e16de5037cce2251441a189c449a8f9ffcccc8a87cdfc596cd21d7c-WX20190611-195017@2x.png)


```go
func plusOne(digits []int) []int {
    add := 1
    for length := len(digits)-1; length >= 0 && add > 0; length-- {
        sum := digits[length] + add
        add = sum / 10
        digits[length] = sum % 10
    }
    
    if add > 0 {
        digits = append([]int{add}, digits...)
    }
    return digits
}
```