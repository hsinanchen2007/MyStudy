利用map的特性key不会重复，将words对应的莫尔斯码当作key值按个添加到一个map中去，然后计算该map的长度（元素个数）即可
实现如下
func uniqueMorseRepresentations(words []string) int {
	var dict = [...]string{".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
		"---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
		".--", "-..-", "-.--", "--.."}
	var res = make(map[string]string)
	var conv = func(S string) string {
		var rets = ""
		for _, v := range S {
			rets += dict[v-'a']
		}
		return rets
	}
	for _, v := range words {
		res[conv(v)] = v
	}

	return len(res)
}