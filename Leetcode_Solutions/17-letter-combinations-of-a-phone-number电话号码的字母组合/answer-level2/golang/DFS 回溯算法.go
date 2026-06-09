### 解题思路
此处撰写解题思路

### 代码

```golang
func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return nil
	}
	wordDict := make(map[string]string, 9)
	wordDict["1"] = ""
	wordDict["2"] = "abc"
	wordDict["3"] = "def"
	wordDict["4"] = "ghi"
	wordDict["5"] = "jkl"
	wordDict["6"] = "mno"
	wordDict["7"] = "pqrs"
	wordDict["8"] = "tuv"
	wordDict["9"] = "wxyz"
	res := []string{}
	subRes := ""
	dfs(digits, 0, &res, subRes, wordDict)
	return res
}

func dfs(digits string, begin int, res *[]string, subRes string, wordDict map[string]string) {

	if begin >= len(digits) {
		*res = append(*res, subRes)
		return
	}
	allChar := wordDict[string(digits[begin])]
	for i := 0; i < len(allChar); i++ {
		subRes += string(allChar[i])
		dfs(digits, begin+1, res, subRes, wordDict)
		subRes = subRes[:len(subRes)-1]
	}
	return
}
```