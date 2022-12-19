### 解题思路
其实也就是判断两个数中有多少位是不一样的。因为右移的话是补符号位，因此出现负数的话就会出错，因此要左移

### 代码

```golang
func convertInteger(A int, B int) int {
    // 因为右移的话是补符号位，因此出现负数的话就会出错，因此要左移
    count := 0
    for A!=0 || B!=0 {
        if A&0x80000000 != B&0x80000000 {
            count++
        }
        A <<= 1
        B <<= 1
    }
    return count
}
```