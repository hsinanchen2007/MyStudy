	if len(strs) < 1 {
		return ""
	}
	l := len(strs[0])
	i := 0
	result := ""
u:
	for l > 0 {
		temp := strs[0][i : i+1]
		for j := 1; j < len(strs); j++ {
			if len(strs[j]) < i+1 || temp != strs[j][i:i+1] {
				break u
			}
		}
		result += temp
		l--
		i++
	}
	return result