```
// 贪心，从最大可匹配的值进行匹配
func intToRoman(num int) string {
    if num <1 {
        return ""
    }
    nums := []int {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
    romans := []string {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"} // 全部是这13种字符的拼接
    i:=0
    var buffer bytes.Buffer // 字符串队列
    for num>0 && i<13{
        if num>=nums[i] {
            buffer.WriteString(romans[i]) // 实现字符串拼接
            num = num-nums[i]
        } else {
            i++
        }
    }
    return buffer.String() // 将未读的转为string返回
}
```