strings.Replace() 之类的固然可以，而且说了是 ipv4 的情况下，可以指定参数 4

尽量减少复制次数

```
func defangIPaddr(address string) string {
	buf := ""
	begin := 0

	for i, c := range address {
		if c == '.' {
			buf += address[begin:i] + "[.]"
			begin = i + 1
		}
	}

	return buf + address[begin:]
}
```
