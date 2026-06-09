利用切片去模拟一个栈，实现本题
![实现效果](https://pic.leetcode-cn.com/24479ba83e93661150bf0aba2c5eedaa393ecf3084728b20e1b42530bf1c8709-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200124142908.png)

```
func isValid(s string) bool {
	if len(s)%2!=0{
		return false
	}
	var res []byte
	for i:=0;i<len(s);i++{
		switch s[i] {
		case '}':
			if len(res)!=0&&res[len(res)-1]=='{' {
				res=res[:len(res)-1]
			}else {
				return false
			}
		case ']':
			if len(res)!=0&&res[len(res)-1]=='[' {
				res=res[:len(res)-1]
			}else {
				return false
			}
		case ')':
			if len(res)!=0&&res[len(res)-1]=='(' {
				res=res[:len(res)-1]
			}else {
				return false
			}
		default:
			res = append(res, s[i])
		}
	}
	if len(res)!=0{
		return false
	}else{
		return true
	}
}
```
