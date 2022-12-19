//递归
func countAndSay(n int) string {
	nextStr := ""
	if n == 1 {
		return "1"
	} else {
        //此处利用递归当需要获取第二个数据时 就需要获取上一个数据
		str := countAndSay(n - 1)
        //当前数据的转化值
		for i := 0; i < len(str); i++ {
			if i != len(str)-1 {
				j := i
				count := 1
				for {
					if j == len(str)-1 {
						break
					}
					if string(str[j]) == string(str[j+1]) {
						count++
					} else {
						break
					}
					j++
				}
				nextStr += strconv.Itoa(count) + string(str[i])
				i += count - 1
			} else {
				nextStr += "1" + string(str[i])
			}
		}
	}
	return nextStr
}
//正则
func countAndSay(n int) string {
    str:="1"
	if n==1{
		return str
	}
	for i:=1;i<n;i++{
		nextstr:=""
		//获取第i次的数据
		for j:=0;j<len(str);j++{
			val:=string(str[j])
			//正则查询以val开头分组获取临近相同数个数 str=11 val=1  rstr[0]=[11]
			reg := regexp.MustCompile("(^"+val+"+)")
			//str[j:] 将已经处理的去掉
			rstr:=reg.FindAllString(str[j:],1)
			nextstr+=strconv.Itoa(len(rstr[0]))+val
			j+=len(rstr[0])-1
		}
		//将第i次的数据给str
		str=nextstr
	}
	return str
}