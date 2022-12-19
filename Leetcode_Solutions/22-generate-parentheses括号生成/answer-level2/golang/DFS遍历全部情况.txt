DFS遍历全部情况，结束条件：
1、left表示已用左括号数，left不能大于n；
2、right表示已用右括号数，right必须小于等于已用左括号数；
3、全部括号都使用，则找到一个正确解
```
func generateParenthesis(n int) []string {
    if n <= 0 {
        return []string{}
    }
	var res = []string{}
	var buf = []string{"("}
	var step = func(buf []string, left, right int) {} // 必须加{}
	step = func(buf []string, left, right int) {
        // 结束条件
		if left > n || right > left{
			return
		}
		if len(buf) == 2*n {
			var str = strings.Join(buf, "")
			res = append(res, str)
		}
		// option 1
		step(append(buf, "("), left+1, right)
		// option 2
		step(append(buf, ")"), left, right+1)
	}
	var left = 1
	var right = 0
	step(buf, left, right)

	return res
}


```