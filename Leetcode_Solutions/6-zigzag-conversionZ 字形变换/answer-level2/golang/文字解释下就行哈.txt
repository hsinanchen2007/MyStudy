1. 首先创建一个长度为 numRows 的字符串数组 list, 用于存放每一层的字符串
2. 给定 next 方向标确保转向
3. 给定 step 标记当前下标字符串需要被添加到 list 对应的下标位置
4. 需要注意 (step == 0 && next != 1)这个判断是为了避免开始时的错误转向
```golang []
func convert(s string, numRows int) string {
	if numRows < 2{
		return s
	}
	var res string
	list := make([]string,numRows)
	next := 1                   //转向标
	step := 0                   //当前待填充的阶
	for i := 0;i<len(s);i++{
		str := string(s[i])
		list[step] += str
		if step == numRows - 1 || (step == 0 && next != 1) {
			next *= -1
		}
		step += next
	}
	for i:=0;i<len(list);i++{
		res += list[i]
	}
	return res
}
```