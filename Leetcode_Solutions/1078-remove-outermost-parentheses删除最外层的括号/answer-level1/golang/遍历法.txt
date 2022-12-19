最无脑的就是遍历
有2个变量，count和index，分别表示遇到的左括号的次数和单独的左括号的数量
```
循环{
  若当前字符是左括号字符{
    count和index都分别加一
  }否则index减一
  若index是大于0且count不等于1则将该字符加到结果字符里
  最后判断若index为0则count归0
}
```

通过左右括号互相抵消来实现

go代码实现如下：
```
func removeOuterParentheses(S string) string {
	start,count:=0,0
	result:=""
	left:="("[0]
	for i:=range S{
		v:=S[i]
		if v==left{
			count+=1
			start+=1
		}else{
			start-=1
		}
		if start>0&&count!=1{
			result+=string(v)
		}
		if start==0{
			count=0
		}
	}
	return result
}
```