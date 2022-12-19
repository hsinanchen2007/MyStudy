思路:
用切片模拟一个栈，遍历字符串，遇到左括号入栈，遇到右括号，做两个判断如果不符合则直接退出，判断1：当前栈是否为空，如果为空则肯定不符合；判断2：栈顶的元素是否是对应的左括号。如果两个判断都满足，则可以将栈顶元素弹出（stack=stack[:len(stack)-1]）。最后判断栈是否为空即可。

```
func isValid(s string) bool {
	stack:=make([]int32,0)
	maps:=map[int32]int32{
		'}':'{',
		']':'[',
		')':'(',
	}
	for _,char:=range s{
		if char=='{'||char=='('||char=='['{
			stack=append(stack,char)
		}else{
			if len(stack)==0{
				return false
			}
			if maps[char]!=stack[len(stack)-1]{
				return false
			}else {
				//相等出栈
				stack=stack[:len(stack)-1]
			}
		}
	}
	if len(stack)==0 {
		return true
	}else {
		return false
	}
## }
```
