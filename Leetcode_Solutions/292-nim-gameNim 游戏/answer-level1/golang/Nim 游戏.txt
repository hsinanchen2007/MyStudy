只要轮到你的石头数量不是4的倍数，意味着 `n%4!=0` 时就胜利


``` go
func canWinNim(n int) bool {
	return n&3 != 0
}
```