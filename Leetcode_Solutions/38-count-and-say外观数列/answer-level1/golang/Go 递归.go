```
//水平扫描，末尾哨兵

func countAndSay(n int)  string{
	//设置出口
	if n == 1{
		return "1"
	}
	str := countAndSay(n-1)
	result := strings.Builder{}
	arrb:=append([]byte(str),' ')
	start,end := 0,0
	for range arrb{
		if arrb[start]!= arrb[end]{
			temp := arrb[start]
			num := end-start
			start = end
			result.WriteString(strconv.Itoa(num))
			result.WriteByte(temp)
		}
		end ++
	}
	return result.String()
}

```