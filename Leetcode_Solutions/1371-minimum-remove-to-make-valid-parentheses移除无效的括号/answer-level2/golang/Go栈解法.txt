使用栈，每当有左括号就入栈
那么什么时候是入栈的是应该被删除的右括号？
实际上，只要栈不为空，那么这个右括号就可以匹配栈顶的左括号，于是栈弹出栈顶元素即可
即栈为空时出现的右括号应该被删除
什么时候左括号应该被删除？
可以等到字符串遍历完成，一次结清，因为如果所有左右括号匹配，那么必然在字符串遍历完成后，栈也为空，那么反之，遍历完成后，栈不为空，那么栈里的左括号都应该被删除
```golang
func minRemoveToMakeValid(s string) string {
	var stack []int
	bytes:=[]byte(s)
	i:=0
	for i<len(bytes){
		if bytes[i]=='('{
			stack=append(stack,i)
		}
		if bytes[i]==')'{
			if len(stack)==0{
				bytes=append(bytes[0:i],bytes[i+1:]...)
				i--
			}else{
				stack=stack[:len(stack)-1]
			}
		}
		i++
	}
	if len(stack)!=0{
		for j:=len(stack)-1;j>=0;j--{
			bytes=append(bytes[0:stack[j]],bytes[stack[j]+1:]...)
		}
	}
	return string(bytes)
}
```