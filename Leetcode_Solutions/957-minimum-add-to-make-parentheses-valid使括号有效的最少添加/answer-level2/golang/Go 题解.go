思路：遍历字符串，分别对左右括号按照以下规则计数，最后返回左右括号数之和即为需要添加的括号数。
1. 左括号计数：单纯递增
2. 右括号计数：当左括号数为零时右括号数递增，当左括号数不为零时左括号数递减

```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2 MB, 在所有 Go 提交中击败了50.00%的用户
```
```Go []
func minAddToMakeValid(S string) int {
	var l, r int
	for i := range S {
		if S[i] == '(' {
			l++
		} else {
			if l > 0 {
				l--
			} else {
				r++
			}
		}
	}
	return l + r
}
```
[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)