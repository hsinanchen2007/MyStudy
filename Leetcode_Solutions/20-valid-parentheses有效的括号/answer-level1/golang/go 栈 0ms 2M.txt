结题思路：
1.用一个切片c保存未匹配的字符
2.symbol用来保存右括号与左括号的对应关系，因为只有右括号出现的时候才可能匹配到左括号，从切片c中出栈
3.判断条件：栈内有字符&&当前字符与栈顶字符匹配
```
func isValid(s string) bool {
	var c  []byte
	symbol := map[byte]byte {
		')' : '(',
		']' : '[',
		'}' : '{',
	}
	for _, value := range s {
		clen := len(c)
		if clen>0 {
			if _,ok := symbol[byte(value)]; ok {
				if c[clen-1]==symbol[byte(value)] {
					c = c[:clen-1]
					continue
				}
			}
		}
		c = append(c,byte(value))
	}
	return len(c)==0
}
```
