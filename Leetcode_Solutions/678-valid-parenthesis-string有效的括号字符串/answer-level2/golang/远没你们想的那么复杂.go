### 解题思路
主需要遍历正序倒序遍历两次即可，第一次把星号当左括号看，第二次把星号当右括号看，只要不符合就中断。

### 代码

```golang

func checkValidString(s string) bool {
	leftCount, rightCount := 0, 0
	for _, c := range []byte(s) {
		if c == ')' {
			rightCount++
		} else {
			leftCount++
		}
		if rightCount > leftCount {
			return false
		}
	}
	leftCount, rightCount = 0, 0
	for i := len(s) -1 ; i >= 0; i-- {
		c := s[i]
		if c == '(' {
			leftCount++
		} else {
			rightCount++
		}
		if leftCount > rightCount {
			return false
		}
	}
	
	return true
}

```