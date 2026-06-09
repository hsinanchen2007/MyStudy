### 解题思路
其实就是统计有多少位不一样。因此可以让A和B异或，然后统计结果中有多少位为1就行。要注意要用左移，不能用右移，因为如果是负数的话，右移就是补符号位，会出错。

### 代码

```golang
func convertInteger(A int, B int) int {
    // 因为右移的话是补符号位，因此出现负数的话就会出错，因此要左移
    count := 0
    tmp := A ^ B
    for tmp != 0 {
        if tmp&0x80000000 == 0x80000000 {
            count++
        }
        tmp <<= 1
    }
    return count
}
```