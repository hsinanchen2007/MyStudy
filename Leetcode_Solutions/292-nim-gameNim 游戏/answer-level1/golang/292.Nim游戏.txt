### 解题思路
从后向前迭代，
.......XYYYXYYYXYYYXYYY

在Y位有出手机会的话，稳赢，同时要保证对手被迫拿到X位的石头。
结果就是模4，有剩余就稳赢

### 代码

```golang

func canWinNim(n int) bool {
	return n%4 != 0
}
```