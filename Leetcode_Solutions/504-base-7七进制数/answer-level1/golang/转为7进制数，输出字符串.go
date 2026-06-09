### 解题思路
此处撰写解题思路

### 代码

```golang
func convertToBase7(num int) string {
	res:=""
    if num==0{
		return "0"
	}
	flag:=false
	if num<0{
		flag=true
		num=-num
	}
	for num>0{
		v:=strconv.Itoa(num%7)
		res=v+res//不能用res+=v 字符串拼接有顺序要求
		num/=7
		fmt.Printf("%s  \n",v)
	}
	if flag{
		res="-"+res
	}
	return res
}
```