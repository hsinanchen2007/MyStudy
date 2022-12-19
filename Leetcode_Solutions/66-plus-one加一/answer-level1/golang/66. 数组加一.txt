#### 思路

- 从前向后遍历，维护进位，确定终止条件
- 循环结束，数组溢出，需要额外替换和追加元素

```
func plusOne(digits []int) []int {
    //进位标志
    tag := 1
    //从后向前遍历的指针
    index := len(digits)-1
    //当指针到头部，或者进位标志位0停止循环
    for index >= 0 && tag != 0 {
        if digits[index] + tag == 10 {
            tag = 1
            digits[index] = 0
            index--
        }else{
            digits[index] =  digits[index] +1
            tag = 0
        }
    }
    //如果数组溢出，进行一次替换和追加元素
    if tag == 1{
        digits[0] = 1
        digits = append(digits,0)
    }
    return digits
}
```
