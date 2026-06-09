### 解题思路
golang两种方式，一种是每位数字进行反转，思路为模除10取余，暂存数值乘以10+余数，最后判断是否溢出（PS：这种方式代码行数少，但是运行时间长）

另一种，先将原数值转为字符串，然后进行反转，进行符号处理，最后判断是否溢出（PS:代码行数较多，思路比较简单，执行时间短）



### 代码

```golang
func reverse(x int) int {
    var max = 0x7fffffff
	var min = -0x80000000

	n := 0

	for ;x!=0;{
		temp := x % 10  
		x = x / 10
		n = n*10 + temp 
	}

	if n>max || n<min{
		return 0
	}
	return n
}

func reverse(x int) int {
    var max = 0x7fffffff
	var min = -0x80000000
	var ss string
	if x<0{
		ss=strconv.Itoa(-x)
	}else{
		ss=strconv.Itoa(x)
	}
	var temp strings.Builder
	for i:=len(ss)-1;i>=0;i--{
		temp.WriteByte(ss[i])
	}

	n,_:=strconv.Atoi(temp.String())
	if x<0{
		n=-n
	}
	if n>max || n<min{
		return 0
	}
	return n
}
```