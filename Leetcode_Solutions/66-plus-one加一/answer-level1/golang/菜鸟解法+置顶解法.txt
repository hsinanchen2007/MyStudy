# 菜鸟解法
```golang
func plusOne(digits []int) []int {
    
    // 进位
    carry := 0
    // 每一位的新值
    newVal := 0
    
    for i := len(digits) - 1; i >= 0; i-- {
        if i == len(digits) - 1 { // 末位+1
            newVal = digits[i] + 1
        } else if carry == 1 { // 其他位，如果有进位，则+1
            newVal = digits[i] + carry
        }
        if newVal == 10 { // 如果当前位的值等于10，则进位，然后重置为0
            carry = 1
            newVal = 0
        } else { // 没有进位
            carry = 0
        }
        digits[i] = newVal // 给当前位赋值
        if carry == 0 { // 如果没有进位，则不用处理前几位了，退出循环
            break
        }
    }
    
    // 如果遍历完数组，还有进位没有处理，则在数组开头增加一个元素:1
    if carry == 1 { 
        digits = append([]int{1}, digits...)
    }
    
    return digits
}
```

# 置顶解法
翻译置顶的解法，确实比较巧妙
```golang
func plusOne(digits []int) []int {
    
    for i := len(digits) - 1; i >= 0; i-- {
        digits[i]++
        digits[i] = digits[i] % 10
        if digits[i] != 0 {
            return digits
        }
    }
    
    // 这两行是神来之笔，专治9,99,999,...
    digits = make([]int, len(digits) + 1)
    digits[0] = 1
    
    return digits
}
```

