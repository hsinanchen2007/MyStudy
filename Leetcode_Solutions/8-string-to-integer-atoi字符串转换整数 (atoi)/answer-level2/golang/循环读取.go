begin用于判断数是否已经开始，negative为负数标记，整体流程比较容易看得懂
![Jietu20200305-235510@2x.jpg](https://pic.leetcode-cn.com/f53b4e39598eb60b175d020982333910f0b927400962b44474256520c7d2e788-Jietu20200305-235510@2x.jpg)

```go
func myAtoi(str string) int {
	res, negative, begin := 0, false, false
	for _, value := range str {
		if value == ' ' && !begin {
			continue
		}
		if (value == '+' || value == '-') && !begin {
			if value == '-' {
				negative = true
			}
			begin = true
			continue
		}
		if value >= '0' && value <= '9' {
			if !begin {
				begin = true
			}
			res = res*10 + int(value-48)
            if res > (-math.MinInt32) && negative {
				res = math.MinInt32
                negative = false
				break
			}
			if res > math.MaxInt32 && !negative {
				res = math.MaxInt32
				break
			}
		} else {
			break
		}
	}
	if negative {
		res = (-res)
	}
	return res
}
```
