### 解题思路

(1)求两个字符串长度的最大公因数l
(2)从某一字符串开头，截取l长度的字符串sub
(3)循环连接sub，判断能否组成两个原始字符串
(4)若能，返回sub，不能，返回空字符串


### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
	l := gcd(len(str1),len(str2))
	sub := str1[:l]
	if check(sub,str1) && check(sub,str2) {
		return sub
	}
	return ""

}
func gcd(a int,b int) int {
	for {
		c := a % b
		if c == 0 {
			return b
		}else {
			a = b
			b = c
		}
	}
}
func check(s1 string,s2 string) bool {
	l := len(s2) / len(s1)
	tmp := ""
	for i := 0;i < l;i++ {
		tmp += s1
	}
	return tmp == s2
}
```