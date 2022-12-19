### 解题思路
看评论里面有提到IM这个非法输入，巧的是在我这个TestCase里面也可以得到预期的999。
题目已经明确是合法的罗马数字，非法输入可以忽略。

执行用时 :4 ms, 在所有 Go 提交中击败了96.18% 的用户
内存消耗 :3.1 MB, 在所有 Go 提交中击败了69.10%的用户

### 代码

```golang
var MapRoman = map[string]int{"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

func romanToInt(s string) int {
	num := 0
	next := 0 // 后一字符代表的值
	for i := len(s); i > 0; i-- {
		val := MapRoman[s[i-1:i]] // 当前值
		if val < next {
			num -= val
		} else {
			num += val
		}
		next = val
	}
	return num
}
```