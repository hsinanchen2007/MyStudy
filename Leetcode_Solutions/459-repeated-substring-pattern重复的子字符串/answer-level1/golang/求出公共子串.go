### 解题思路
此处撰写解题思路

### 代码

```golang
func repeatedSubstringPattern(s string) bool {
	if len(s)==1{
		return false
	}
	var str string
	var index int
	for i:= 0;i< len(s)/2;i++{
		if s[:i+1]==s[len(s)-1-i:]{//从前往后，同时从后往前找出公共子串，原字符串要么是 公共子串的偶数倍，要么是公共子串的奇数倍
			//str= s[i+1:len(s)-1-i]
			index=i
		}
	}
	fmt.Println(index)
	//如果s是公共子串的偶数倍，则 len(s[:index+1])*2== len(s) 做乘法不会丢失精度，如果用len(s)/2去跟len(s[:index+1])比较，可能会丢失/2之后的余数
	if len(s[:index+1])*2== len(s){//这时是子串的偶数倍
		str= s[:index+1]
	}else{
		str= s[index+1:len(s)-1-index]
	}
	fmt.Println(str)
	n:= len(str)
	for len(s)> 0{
		if len(s)<n{
			return false
		}
		if s[:n]==str{
			s=s[n:]
		}else{
			return false
		}
	}
	

	return true
}
```