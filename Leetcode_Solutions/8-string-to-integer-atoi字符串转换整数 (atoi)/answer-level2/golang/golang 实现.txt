```
func myAtoi(str string) int {
	MIN:=-1<<31
	MAX:=1<<31-1
	i := 0
	flag:=1
	
	//特殊判断
	if len(str) == 0 {
		return 0
	}
	//去除空格
	for str[i] == ' ' {
		i++
		if i>=len(str){
			return 0
		}
	}
	//判断符号
	switch str[i] {
	case '-':
		flag= -1
		i++
	case '+':
		i++
	}
	//寻找数值部分
	res := 0
	for i < len(str) && str[i] >= '0' && str[i] <= '9' {
		res = res*10 + int(str[i]-'0')*flag
		i++
		if res<MIN{
			return MIN
		}
		if res>MAX{
			return MAX
		}
	}
	return res
}
```