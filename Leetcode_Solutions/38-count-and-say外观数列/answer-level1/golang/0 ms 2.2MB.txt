### 解题思路
递归+哨兵

### 代码

```golang
func countAndSay(n int) string {
    if n == 1 {
		return "1"
	}
	pre := countAndSay(n-1) + "#"
	var res strings.Builder
	n = 1

	for i := range pre[:len(pre)-1] {
		if pre[i] != pre[i+1] {
			res.WriteString(strconv.Itoa(n))
			res.WriteByte(pre[i])
			n = 1
		} else {
			n++
		}
	}
	return res.String()
}
```