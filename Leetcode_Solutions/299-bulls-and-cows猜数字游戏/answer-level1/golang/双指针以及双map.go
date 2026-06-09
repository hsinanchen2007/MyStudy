### 解题思路
此处撰写解题思路

### 代码

```golang
func getHint(secret string, guess string) string {
	l1, l2 := len(secret), len(guess)
	if l1 != l2 {
		return ""
	}
	k1, k2 := 0, 0
	for i := 0; i < l1; i++ {//统计位置正确
		if secret[i] == guess[i] {
			k1++
		}
	}
	secs := strings.Split(secret, "")
	gues := strings.Split(guess, "")
	sort.Strings(secs)
	sort.Strings(gues)
	//统计相同值对数
	i, j := 0, 0
	for i < l1 && j < l1 {
		if secs[i] == gues[j] {
			i++
			j++
			k2++
		} else if secs[i] > gues[j] {
			j++
		} else {
			i++
		}
	}
	return fmt.Sprintf("%dA%dB", k1, k2-k1)
}

```

```golang
func getHint(secret string, guess string) string {
	l1, l2 := len(secret), len(guess)
	if l1 != l2 {
		return ""
	}
	j, k := 0, 0
	m := map[uint8]int{}
	m1 := map[uint8]int{}
	for i := 0; i < l1; i++ {
		if secret[i] == guess[i] {//统计位置正确
			j++
		} else {
			m[secret[i]]++
			m1[guess[i]]++
		}
	}
	//统计位置不正确
	for key, v := range m {
		k+=minGetHint(v,m1[key])
	}
	return fmt.Sprintf("%dA%dB",j,k)
}
func minGetHint(a,b int) int{
	if a<b{
		return a
	}
	return b
}
```