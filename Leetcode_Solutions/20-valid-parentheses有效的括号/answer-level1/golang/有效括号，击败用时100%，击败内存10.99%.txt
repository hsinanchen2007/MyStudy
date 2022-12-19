### 解题思路
1. 括号左右对应匹配，同时存在可能相隔多个括号后才会有匹配的，所以考虑用栈。这里用slice代替
2. 用一个map存右括号和左括号的映射情况，发现是右括号，则和栈尾元素对比，匹配则出栈，否则加入栈
3. 最终如果栈为空，则完全匹配返回true，否则false
4. 最开始判断，字符串不为双数直接返回false，因为满足题目要求的字符串必定为双数

### 代码

```golang
func isValid(s string) bool {
    soruce := strings.Split(s, "")
	//如果输入空字符串，返回true
	//如果字符串不是双数，肯定错误返回false
	if len(soruce) % 2 == 1 {
		return false
	}
	//zhan，做栈用
	zhan := []string{}
	tmap := map[string]string{
		")" : "(",
		"]" : "[",
		"}" : "{",
	}

	for _, v:= range soruce{
		//如果栈为空，直接加入到栈维
		if len(zhan) == 0{
			zhan = append(zhan, v)
			continue
		}
		//如果在映射中没找到，则肯定为左边的括号，直接加入到栈中
		if len(tmap[v]) == 0{
			zhan = append(zhan, v)
			continue
		}
		//如果栈尾与映射的值相同，表明可以匹配括号。栈尾pop
		if tmap[v] == zhan[len(zhan)-1]{
			zhan = zhan[: len(zhan)-1]
		}
	}
	//最后如果栈为空，表明完全匹配，发挥true
	if len(zhan) == 0 {
		return true
	}
	return  false
}
```