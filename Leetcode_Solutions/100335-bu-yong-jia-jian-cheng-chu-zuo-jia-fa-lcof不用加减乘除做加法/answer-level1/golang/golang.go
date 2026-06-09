### 解题思路
异或运算，参考加法器的实现

### 代码

```golang
func add(a int, b int) int {
    for b != 0 {
        tmp := a ^ b
        b = (a & b) << 1
        a = tmp
    }
    return a
}
```