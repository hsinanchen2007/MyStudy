func removeDuplicateLetters(s string) string {
	if len(s) == 0 {
		return ""
	}

	stack := make([]rune, 0)
	runeMap := make(map[rune]int)
	siteMap := make(map[int]rune)
	stackMap := make(map[rune]int)

	runes := []rune(s)
	for i, val := range runes {
		siteMap[i] = val
		if _, ok := runeMap[val]; ok {
			runeMap[val]++
		} else {
			runeMap[val] = 1
		}
	}

	stack = append(stack, runes[0])
	stackMap[runes[0]] = 1

	for i := 1; i < len(runes); {

		if len(stack) == 0 {
			stack = append(stack, runes[i])
			stackMap[runes[i]] = 1
			i++
		} else if _, ok := stackMap[runes[i]]; ok {
			runeMap[runes[i]]--
			i++
		} else if runes[i] < stack[len(stack)-1] {
			if num, ok := runeMap[stack[len(stack)-1]]; ok && num > 1 {
				runeMap[stack[len(stack)-1]]--
				delete(stackMap, stack[len(stack)-1])
				stack = stack[:len(stack)-1]
				continue
			} else if num, ok := stackMap[runes[i]]; !ok || num == 0 {
				stack = append(stack, runes[i])
				stackMap[runes[i]] = 1
			}
			i++

		} else if runes[i] > stack[len(stack)-1] {
			fmt.Println(i)
			if num, ok := stackMap[runes[i]]; !ok || num == 0 {
				stack = append(stack, runes[i])
				stackMap[runes[i]] = 1
			}
			i++
		} else if runes[i] == stack[len(stack)-1] {
			runeMap[stack[len(stack)-1]]--
			i++
		}
	}

	result := ""
	for _, val := range stack {
		result += string(val)
	}
	return result
}