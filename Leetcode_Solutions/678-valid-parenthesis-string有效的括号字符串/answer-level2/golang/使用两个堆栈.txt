解题思路
“（”必须在“”的左边
“）”必须在“”的右边

使用两个栈，left存左括号，star存“*”，存储的内容是字符在字符串中的下标。

1 遍历字符串的每一个字符，如果是“（”存储下标到left中；
2 如果是“*”存储下标到star中；
3 如果是“）”，先从left中获取“（”，并将栈顶元素出栈，如果left为空，则从star中获取“*”，将栈顶元素出栈，如果star也为空，则返回false；
4 按照1 2 3 遍历完字符串之后，遍历left，与“*”匹配；
5 如果left为空，返回true；
6 如果left不为空，遍历left，从star栈顶出栈一个“”，如果“”的下标小于left的“（”的下标，那么返回false；如果大于，则left栈顶出栈，star栈顶出栈，进行下一轮比较；
7 如果最后left还有值，star为空，返回false；如果left为空，star有值，返回true。

```
func checkValidString(s string) bool {
	if len(s) == 0 {
		return true
	}
	if s[0] == ')' {
		return false
	}
	left := []int{} // 保存的是下标
	star := []int{}

	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			left = append(left, i)
		}
		if s[i] == '*' {
			star = append(star, i)
		}

		if s[i] == ')' {
			ll := len(left)
			ls := len(star)
			if ll > 0 {
				left = left[:ll-1]
			} else if ls > 0 {
				star = star[:ls-1]
			} else {
				return false
			}
		}
	}
	fmt.Println(len(left), len(star))
	fmt.Println(left, star)
	if len(left) == 0 {
		return true
	}

	for i := len(left)-1; i >= 0; i-- {
		if len(star) == 0 || star[len(star)-1] < left[i] {
			return false
		}
		star  = star[:len(star)-1]
	}
	return true
}

```