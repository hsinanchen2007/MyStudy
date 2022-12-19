### 解题思路
4的倍数必输，否则必赢，代码最少的一道题
### 代码

```golang
func canWinNim(n int) bool {
    return n % 4 != 0
}
```