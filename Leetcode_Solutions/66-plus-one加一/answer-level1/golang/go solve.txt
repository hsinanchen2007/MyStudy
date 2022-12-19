


### 代码

```golang
func plusOne(digits []int) []int {
    i := len(digits) - 1
    for i >= 0 {
        tmp:= digits[i] + 1
        if tmp >= 10{
             digits[i] = 0
        } else {
            digits[i] = tmp
            break
        }
        i --
    }
    if i < 0 {
        digits = append([]int{1}, digits...)
    }
    return digits
}
```