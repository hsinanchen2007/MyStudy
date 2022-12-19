先推出这个位置所在的数是几位数
1-9：  1位数 总数9  写成字符串总长度9
10-99：2位数 总数89 写成字符串总长度180
如果n位于(9 189]区间内，那么n位置所在的数是个两位数
如何推出这个两位数的数值：见代码内


```golang
func findNthDigit(n int) int {
	if n<=9{
		return n
	}
    //找到n所在位置的数是几位数
	d,length,pre:=0,0,0
	for n>length{
		pre=length
		length+=int(math.Pow(10,float64(d)))*9*(d+1)
		d++
	}
    //推出n所在的数temp
	temp:=(n-pre-1)/d+int(math.Pow(10,float64(d-1)))
    //推出具体数值
	str,dig:=strconv.Itoa(temp),(n-pre)%d
	if dig==0{
		dig=d
	}
	res,_:=strconv.Atoi(str[dig-1:dig])
	return res
}
```