func longestValidParentheses(s string) int {
	arr := trimFromLeft(s)
	max := 0
	for _, v := range arr {
		if tmp := countFromRight(v); tmp > max {
			max = tmp
		}
	}
	return max
}

// read s from left to right, and when count( ')' )> count( '(' ), there must be a breakpoint.
// seperate s, and continue read, then we got a string list, witch can be read from left to right.
func trimFromLeft(s string) []string {
	c, last := 0, 0
	ret := []string{}
	for i, v := range s {
		if v == '(' {
			c++
		} else {
			c--
		}
		if c == -1 {
			ret = append(ret, s[last:i])
			last = i + 1
			c = 0
		}
	}
	ret = append(ret, s[last:])
	return ret
}
// read s from right to left, when count( '(' )> count( ')' ), record the length of right part.
// trump right part of s, and continue read, then we get some length of valid parentheses. 
// get max.
func countFromRight(s string) int {
	max, c := 0, 0
	last := len(s) - 1
	for i := last; i >= 0; i-- {
		if s[i] == ')' {
			c++
		} else {
			c--
		}
		if c == -1 {
			l := last - i
			last = i - 1
			c = 0
			if l > max {
				max = l
			}
		}
	}
	if last+1 > max {
		return last + 1
	}
	return max
}