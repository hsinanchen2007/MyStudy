```
func compressString(S string) string {
	if len(S) == 0 {
		return S
	}
	var (
		ans string
		cnt int = 1
		ch      = string(S[0])
	)
	for i := 1; i < len(S); i++ {
		if ch == string(S[i]) {
			cnt++
		} else {
			ans += ch + strconv.Itoa(cnt)
			ch = string(S[i])
			cnt = 1
		}
	}
	ans += ch + strconv.Itoa(cnt)
	if len(ans) >= len(S) {
		return S
	}
	return ans
}
```
