循环清零最低位的1，直到num==0
```
func hammingWeight(num uint32) int {
    result := 0
    for num != 0{
        num = num & (num-1)
        result++
    }
    return result
}
```
