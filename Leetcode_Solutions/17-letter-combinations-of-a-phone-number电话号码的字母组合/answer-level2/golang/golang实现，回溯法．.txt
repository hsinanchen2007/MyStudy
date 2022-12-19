golang实现，回溯法．

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 回溯法
// 时间复杂度：O(3^N*4^M)  空间复杂度：O(3^N*4^M)  其中，N,M分别为代表3个和4个字母的数字的个数
// 对于每个最终的字符串，共有N+M个字符位置，每个位子的字母有3种或4种可能性，回溯法会遍历该字符串的所有组合并存储

var digitMap = map[string]string{"2":"abc", "3":"def", "4":"ghi", "5":"jkl", 
	"6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
var combinations []string

func letterCombinations(digits string) []string {
	if len(digits)==0 {
        return nil
	}
	
    combinations = []string{}  // 重置全局变量
	getCombinations(digits, 0, "")
	return combinations
}

func getCombinations(digits string, index int, str string) {
	if index==len(digits) {
		combinations = append(combinations, str)
		return 
	}

	for _, s := range []rune(digitMap[digits[index:index+1]]) {
		getCombinations(digits, index+1, str+string(s))
	}
}
```

