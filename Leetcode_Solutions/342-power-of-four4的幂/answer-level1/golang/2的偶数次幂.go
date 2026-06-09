```
func isPowerOfFour(num int) bool {
    if num == 0 || num & (num -1) != 0{
        return false
    }
    count:= 0
    for num ^ 1 != 0{
        num>>=1
        count++
    }
    return (count % 2) == 0
}
```
先判断是否是2的幂，再判断是否是偶数次幂
