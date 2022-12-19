# 思路
每将一个字符放入一个栈，就去和栈内的最后一个元素匹配，如果匹配，就从栈中删除这个元素，否则就入栈
扩号要有序，所以每次只需要和栈的最后一个元素进行对比就可以
空字符串为有效，扩号必须有序，{{(}}) 不符合，{{()}} 符合

# 代码
```
func isValid(s string) bool {
	if len(s) == 0 {
		return true
	}
	if len(s)%2 != 0 {
		return false
	}

	//用来匹配的map
	m := map[string]string{
		")": "(",
		"]": "[",
		"}": "{",
	}
	//“栈” 
	var stack []string
	l := len(s)
	for i := 0; i < l; i++ {
		if len(stack) == 0 {
			stack = append(stack, string(s[i]))
		} else {
			//进行匹配，匹配成功，删除栈的最后一个元素，否则，加入到栈中
			if m[string(s[i])] == stack[len(stack)-1] {
				stack = stack[:len(stack)-1]
			} else {
				stack = append(stack, string(s[i]))
			}
		}
	}
	if len(stack) != 0 {
		return false
	} else {
		return true
	}
}

```
