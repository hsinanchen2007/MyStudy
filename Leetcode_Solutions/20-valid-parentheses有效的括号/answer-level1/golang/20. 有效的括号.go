### 解题思路
此处撰写解题思路

### 代码

```golang
func isValid(s string) bool {

	if s == "" {
		return true
	}
	if len(s) < 2 {
		return false
	}
	var stack []string
	for _, v := range s {

		switch string(v) {
		case "}":
			if len(stack) <= 0 {
				return false
			}
			res := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if res != "{" {
				return false
			}
			break
		case "]":
			if len(stack) <= 0 {
				return false
			}
			res := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if res != "[" {
				return false
			}
			break
		case ")":

			if len(stack) <= 0 {
				return false
			}
			res := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if res != "(" {
				return false
			}
			break
		default:
			//fmt.Println(string(v))
			stack = append(stack, string(v))
			break
		}

	}
	if len(stack) > 0 {

		return false
	}

	return true
}
```