![1.png](https://pic.leetcode-cn.com/a78ce2b0a36805774063c0846a365a197cc5db0fd09c799810a4b2ff5251a9f1-1.png)
特地绑定手机号来吐槽一下，在safari提交是4ms，换到chrome变成了0ms
```
func trans(str string, z bool) int {
	a := make([]uint8, 0, len(str))
	for i := 0; i < len(str); i++ {
		if 48 <= str[i] && str[i] <= 57 {
			a = append(a, str[i])
		} else {
			break
		}
	}

	ret := 0
	for i := 0; i < len(a); i++ {
		tmp, _ := strconv.Atoi(string(a[i]))
		ret = ret*10 + tmp
		if ret > (1<<31)-1 {
			if !z {
				return -(1 << 31)
			} else {
				return (1 << 31) - 1
			}
		}
	}

	if !z {
		ret *= -1
	}

	return ret
}

func myAtoi(str string) int {
	s := false
	z := false
	f := false
	for i := 0; i < len(str); i++ {
		if str[i] == 32 {
			continue
		}
		if str[i] == 45 {
			s = true
			f = true
		} else if str[i] == 43 {
			s = true
			z = true
			f = true
		} else if 48 <= str[i] && str[i] <= 57 {
			s = true
			z = true
		} else {
			return 0
		}

		if s {
			if f {
				return trans(str[i+1:], z)
			} else {
				return trans(str[i:], z)
			}
		}
	}

	return 0
}
```
