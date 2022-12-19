```
var ansMap map[string]bool

func removeInvalidParentheses(s string) []string {
	if s == "" {
		return []string{""}
	}
	ansMap = make(map[string]bool)
	ans := make([]string, 0)
	lcnt, rcnt := GetRemoveCnt(s)
	helper1("", s, 0, lcnt, rcnt)
	for k, _ := range ansMap {
		ans = append(ans, k)
	}
	return ans

}

func helper1(pre, s string, stackcnt, lcnt, rcnt int) {
	if lcnt == 0 && rcnt == 0 {
		isValid(pre, s, stackcnt)
		return
	}
	if lcnt < 0 || rcnt < 0 || s == "" {
		return
	}

	if s[0] != '(' && s[0] != ')' {
		pre += s[:1]
		helper1(pre, s[1:], stackcnt, lcnt, rcnt)
	}
	if s[0] == ')' {
		if stackcnt == 0 { //delete
			helper1(pre, s[1:], stackcnt, lcnt, rcnt-1)
		} else {
			helper1(pre, s[1:], stackcnt, lcnt, rcnt-1) //delete
			pre += s[:1]
			helper1(pre, s[1:], stackcnt-1, lcnt, rcnt) //use
			pre = pre[:len(pre)-1]
		}
	}
	if s[0] == '(' {
		helper1(pre, s[1:], stackcnt, lcnt-1, rcnt) //delete
		pre += s[:1]
		helper1(pre, s[1:], stackcnt+1, lcnt, rcnt) //use
		pre = pre[:len(pre)-1]
	}

}

func isValid(pre, s string, stackcnt int) {
	for i := 0; i < len(s); i++ {
		if s[i] != '(' && s[i] != ')' {
			continue
		}
		if s[i] == ')' {
			if stackcnt == 0 {
				return
			}
			stackcnt--
		}
		if s[i] == '(' {
			stackcnt++
		}
	}
	if stackcnt == 0 {
		ansMap[string(pre)+s] = true
	}
}

func GetRemoveCnt(s string) (int, int) {
	n := len(s)
	lcnt, rcnt := 0, 0
	for i := 0; i < n; i++ {
		if s[i] != '(' && s[i] != ')' {
			continue
		}
		if s[i] == '(' {
			lcnt++
		}
		if s[i] == ')' {
			if lcnt == 0 {
				rcnt++
			} else {
				lcnt--
			}
		}
	}
	return lcnt, rcnt
}
```
