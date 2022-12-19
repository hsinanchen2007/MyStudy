看题目可以知道这是在考自动机，于是先画出有限自动机(DFA)，然后用双层case来写代码，题目给出的样例里面只说了输入`-`需要输出负数，写代码过程中发现样例里面有`+`的情况也需要处理，所以，最后画出来的有限自动机如图

![image.png](https://pic.leetcode-cn.com/6f41d21e6317569c64b06d6e7eabf334c9196d7591fa8bf96c53f83ef2789626-image.png)

里面检查到`+/-`的时候修改变量`isPositive`的值

没有用switch case，用的if else，思路和switch case一样的

题目的最后限制了int32的大小，由于我写go语言太菜了，偷懒直接对最后的结果大小进行判别

官方的题解是用的表驱动的写代码，在情况比较简单的时候比较适合，比较复杂的时候表就比较大了。
```go

func myAtoi(str string) int {
	var result []uint8
	state := 1
	pos := -1
	//isPositive = 1
	var isPositive int32 = 1
	for {
		pos += 1
		if pos >= len(str) {
			state = 4
		}
		if state > 4 && state <= 1 {
			// 使用for break来实现while的功能
			break
		} else if state == 1 {
			if str[pos] == ' ' {
				// 前导0则继续
				continue
			} else if str[pos] == '-' {
				isPositive = -1
				state = 2

			} else if str[pos] == '+' {
				isPositive = 1
				state = 2
			} else if str[pos] <= '9' && str[pos] >= '0' {
				state = 2
				result = append(result, str[pos]-'0') // 当前字符的ascii码减去0的ascii码，就是他的数字的大小
			} else {
				state = 4
			}

		} else if state == 2 {
			if str[pos] <= '9' && str[pos] >= '0' {
				state = 2
				result = append(result, str[pos]-'0')
			} else {
				state = 4
			}

		} else if state == 3 {
			if str[pos] <= '9' && str[pos] >= '0' {
				state = 2
				result = append(result, str[pos]-'0')
			} else {
				state = 4
			}

		} else if state == 4 {
			// 检测到其他字符，接收条件
			if len(result) == 0 {
				return 0
			} else {
				// 计算result的值
				var value float64
				//var value int32
				value = 0
				for i := len(result); i > 0; i-- {
					value += math.Pow10(i-1) *float64( result[len(result)-i])
				}
				if isPositive == -1 && value > 2147483648 {
					value = 2147483648
				} else if isPositive == 1 && value >2147483647 {
					value = 2147483647
				}

				fmt.Printf("value: %f, isPositive: %d\n", value, isPositive)
				return int(value*float64(isPositive))

			}

		}

	}

	return 0

}


```