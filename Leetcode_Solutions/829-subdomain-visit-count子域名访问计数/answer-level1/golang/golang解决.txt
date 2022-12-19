分割字符串放hash，然后循环：
func subdomainVisits(cpdomains []string) []string {
ret := []string{}
	mapret := make(map[string]int)
	for _, item := range cpdomains {
		child := strings.Split(item, " ")
		count, _ := strconv.Atoi(child[0])
		desendants := strings.Split(child[1], ".")
		lens := len(desendants)
		tmp := ""
		for i := lens - 1; i >= 0; i-- {
			if i == lens-1 {
				tmp = desendants[i]
			} else {
				tmp = desendants[i] + "." + tmp
			}
			if _, contain := mapret[tmp]; contain {
				mapret[tmp] += count
			} else {

				mapret[tmp] = count
			}
		}

	}
	for k, v := range mapret {
		ret = append(ret, strconv.Itoa(v)+" "+k)
	}

	return ret
}