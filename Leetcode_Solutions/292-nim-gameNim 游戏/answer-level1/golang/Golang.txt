题解一：
```
func canWinNim(n int) bool {
    return n % 4 != 0
}
```
题解二：按位运算
```
func canWinNim(n int) bool {
    return n & 3 != 0
}
```

