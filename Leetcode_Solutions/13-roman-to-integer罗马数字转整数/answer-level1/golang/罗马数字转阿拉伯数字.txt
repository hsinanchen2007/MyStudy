### 解题思路
思考一开始感觉像计算器，可使用栈，后来发现罗马数字特性可用如下步骤：
1。由于一个字符代表一个数字，特殊的字符也仅限于2位，所以可以从字符串后往前进行处理
2.解析成slice，从**后**逐个解析字符，并且相加，直到所有字符相加完成
3。当遇到**当前**一个字符值比前一个字符值小的情况，则累计值减去**当前**值

*此思路利用了罗马数字的特性，效率并非很好值达到超过53.37%用户。但思路相对耿直易懂。*

### 代码

```golang
import "strings"
func romanToInt(s string) int {
    lmap := map[string]int{
		"I":1,
		"V":5,
		"X":10,
		"L":50,
		"C":100,
		"D":500,
		"M":1000,
	}
	
	c := strings.Split(s, "")
	length := len(c)
	result := 0
	last := 0

	for i := length-1; i >= 0; i-- {
		if i == length - 1 {
			last = lmap[c[i]]
			result = last
			continue
		}

		if i < 0 {
			break
		}

		current := lmap[c[i]]

		if current < last {
			result -= current
			//这里一般情况下要加上如下行代码，更新last的值。
			//但由于罗马数字的特性，如果进入了这个if块，且存在下一个数，则肯定比上一个数大，所以可省略。
			// last = current
			continue
		}

		last = current
		result += current
	}
	return result
}
```