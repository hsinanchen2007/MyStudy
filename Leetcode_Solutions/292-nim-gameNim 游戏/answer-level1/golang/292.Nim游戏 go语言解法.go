### 解题思路

只要石头不能被4整除，就能赢。

### 代码

```golang
func canWinNim(n int) bool {
    return (n % 4 != 0)
}
```