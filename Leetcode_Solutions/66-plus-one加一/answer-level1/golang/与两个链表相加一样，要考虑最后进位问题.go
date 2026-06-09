```golang
func plusOne(digits []int) []int {
    l:=len(digits)
    carry := 0
    for i:=l-1;i>=0;i-- {
        t := digits[i] + carry
        if i==l-1{
            t +=1
        }
        num := t%10
        carry = t/10
        digits[i] = num;

        if carry == 0 {
            return digits
        }
    }
    // 考虑最后一个进位问题
    if carry > 0 {
        tmp:= []int{carry}
        digits = append(tmp,digits...)
    }
    return digits
}
```