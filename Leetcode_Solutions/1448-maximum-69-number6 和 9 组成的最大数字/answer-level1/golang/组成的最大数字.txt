### 解题思路
先将数字转化为字符串，再将第一个6变成9就行。再将字符串转化为数字。

### 代码

```golang
func maximum69Number(num int) int {
	s := fmt.Sprintf("%d", num)
	s = strings.Replace(s, "6", "9", 1)
	ret, _ := strconv.Atoi(s)
	return ret
}
```