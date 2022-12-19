### 解题思路
此处撰写解题思路
思路见下面代码

### 代码
```
第一步找出递归算法
numDecodings(s)=numDecodings(s[1:])+numDecodings(2:)
"17314560213"
你会发现60是无法编码的也就是有0的时候前面一个数字只能为1或者2

"12" "02" "10" "27"
最后只剩2位数判断 大于26时或者末尾为0返回值为1种  前面为0返回为0 小于26时返回为2种

"12311" "02311" "73111" "10121"
中间位置判断 第一位数为0返回为0 73>26因此7只能单独放  "73111"种数="3111"的种数 "10121"="121"的种数
```


```golang
var m=map[string]int{}
func numDecodings(s string) int {
	l:=len(s)
	for i:=0;i<l;{
	    index:=strings.Index(s[i:],"0")
	    if index==0{
	    	return 0
		}else if index==-1{
			return numDecodings1(s)
		}else if s[i+index-1]!='1'&&s[i+index-1]!='2'{
			return 0
		}
	    i+=index+1
	}
	return numDecodings1(s)
}
func numDecodings1(s string) int {
	if v,ok:=m[s];ok{
		return v
	}
	l:=len(s)
	if l==1{
		if s=="0"{
			return 0
		}else{
			return 1
		}
	}else if l==2{
		v,_:=strconv.Atoi(s)
		if strings.Contains(s,"0"){
			return 1
		}else if v>26{
			return 1
		}else{
			return 2
		}
	}else{
		v1,v2:=s[0:1],s[1:2]
		v3,_:=strconv.Atoi(s[0:2])
		if v1=="0"{
			return 0
		}
		if v2=="0"{
			m[s]=numDecodings1(s[2:])
			return m[s]
		}
		if v3>26{
			m[s]=numDecodings1(s[1:])
			return m[s]
		}
	}
	m[s]=numDecodings1(s[1:])+numDecodings1(s[2:])
	return m[s]
}
```