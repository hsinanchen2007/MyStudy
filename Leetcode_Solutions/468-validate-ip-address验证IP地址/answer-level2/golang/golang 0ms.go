题目很简单，主要是要细心，一次过还是有点难度的。

ipv4：
- ‘.’ 分隔每组
- 共有4组十进制数字
- 每组长度不能为0
- 不能有前置0，但是可以只有一个0
- 每组数字必须在0到255之前
- 数字前面不能有符号

IPv6：
- ‘:’ 分隔每组
- 共有8组十六进制数字
- 每组长度不能等于0且不能超过4
- 因为是十六进制，所以每组中的字符只能是 0-9,a-f,A-F构成
```
func validIPAddress(IP string) string {
	if checkIPv4(IP) {
		return "IPv4"
	}
	if checkIPv6(IP) {
		return "IPv6"
	}
	return "Neither"
}

func checkIPv4(IP string) bool {
	strs := strings.Split(IP, ".")
	if len(strs) != 4 {
		return false
	}
	for _, s := range strs {
		if len(s) == 0 || (len(s) > 1 && s[0] == '0') {
			return false
		}
		if s[0] < '0' || s[0] > '9' {
			return false
		}
		n, err := strconv.Atoi(s)
		if err != nil {
			return false
		}
		if n < 0 || n > 255 {
			return false
		}
	}
	return true
}

func checkIPv6(IP string) bool {
	strs := strings.Split(IP, ":")
	if len(strs) != 8 {
		return false
	}
	for _, s := range strs {
		if len(s) <= 0 || len(s) > 4 {
			return false
		}
		for i := 0; i < len(s); i++ {
			if s[i] >= '0' && s[i] <= '9' {
				continue
			}
			if s[i] >= 'A' && s[i] <= 'F' {
				continue
			}
			if s[i] >= 'a' && s[i] <= 'f' {
				continue
			}
			return false
		}
	}
	return true
}

```
