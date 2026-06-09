### 解题思路

### 代码

```golang
func convertInteger(A int, B int) int {
    var count int
    A = A & math.MaxUint32
    B = B & math.MaxUint32
    temp := A ^ B
    for temp != 0{
        lowbit := temp & (-temp)
        count++
        temp -= lowbit
    }
    return count
}
```