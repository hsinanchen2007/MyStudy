```
func restoreIPAddresses(s string) []string {
	ips := []string{}

	N := len(s)
	ip := [4]string{}

	var search func(begin, layer int)

	search = func(begin, layer int) {
		// IP 最多 4 段, 定义边界
		if layer == 3 {
			if isIPPart(s[begin:]) {
				ip[layer] = s[begin:]
				ips = append(ips, strings.Join(ip[:], "."))
			}
			return
		}

		// 每个 ip 段最多 3 位长度
		for i := 1; i < 4; i++ {

			// 检查字符串的剩余长度，是否足够分
			if begin+i > N {
				return
			}

			p := s[begin : begin+i]
			if isIPPart(p) {
				ip[layer] = p
				search(begin+i, layer+1)
			}
		}
	}

	search(0, 0)
	return ips
}

func isIPPart(p string) bool {
	if len(p) > 1 && p[0] == '0' {
		return false
	}

	if len(p) > 3 {
		return false
	}

	i, e := strconv.Atoi(p)

	if e != nil {
		return false
	}

	return i >= 0 && i <= 255
}

```
