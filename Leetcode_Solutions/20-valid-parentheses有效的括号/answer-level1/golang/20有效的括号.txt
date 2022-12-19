func isValid(s string) bool {
	if len(s) == 0 {
		return true
	}
	if len(s)%2 != 0 {
		return false
	}
	tmpStack := []string{}

	for _, si := range s {
		if len(tmpStack) == 0 {
			tmpStack = []string{string(si)}
			continue
		}
		if match(tmpStack[len(tmpStack)-1], string(si)) {
			tmpStack = tmpStack[0 : len(tmpStack)-1]
			continue
		}
		tmpStack = append(tmpStack, string(si))
	}
	return len(tmpStack) == 0
}

func match(s1, s2 string) bool {
	if (s1 == "{" && s2 == "}") || (s1 == "(" && s2 == ")") || (s1 == "[" && s2 == "]") {
		return true
	}
	return false
}