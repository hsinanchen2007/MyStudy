### 解题思路
辗转相除法   先判断如果能被AB整除。那么字符串的第一个字符一定是A，末尾一定是B。
两个字符串或者  n个字符串连起来一样满足   AB是其除数


### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
	if str1+str2 != str2+str1{
		return ""
	}
	return str1[0:gcd(len(str1),len(str2))]
}

func gcd(a int,b int) int{
	if(a%b == 0){
		return b
	}else{
		return gcd(b,a%b)
	}
}
```