### 解题思路
此题不难，就是要多考虑边界条件。
暴力也行，DFS也成。
唯尾递归容易些。

### 代码

```golang
func restoreIpAddresses(s string) []string {

	var recur func(s string, l int) []string
	recur = func(s string, l int) []string {
		if len(s) == 0 {
			return []string{}
		}
		if l == 1 && ((len(s) > 1 && s[0] != '0') || len(s) == 1) {
			i, _ := strconv.ParseInt(s, 10, 32)
			if i >= 0 && i <= 255 {
				return []string{s}
			} else {
				return []string{}
			}
		}
		var ret []string
		if len(s) >= 1 {
			t := s[0:1]
			i, _ := strconv.ParseInt(t, 10, 32)
			if i >= 0 && i <= 9 {
				p1 := recur(s[1:], l-1)
				for i := 0; i < len(p1); i++ {
					ret = append(ret, t+"."+p1[i])
				}
			}
		}
		if len(s) >= 2 && s[0] != '0' {
			t := s[0:2]
			i, _ := strconv.ParseInt(t, 10, 32)
			if i >= 10 && i <= 99 {
				p1 := recur(s[2:], l-1)
				for i := 0; i < len(p1); i++ {
					ret = append(ret, t+"."+p1[i])
				}
			}
		}

		if len(s) >= 3 && s[0] != '0' {
			t := s[0:3]
			i, _ := strconv.ParseInt(t, 10, 32)
			if i >= 100 && i <= 255 {
				p1 := recur(s[3:], l-1)
				for i := 0; i < len(p1); i++ {
					ret = append(ret, t+"."+p1[i])
				}
			}
		}
		return ret
	}

	return recur(s, 4)
}
```