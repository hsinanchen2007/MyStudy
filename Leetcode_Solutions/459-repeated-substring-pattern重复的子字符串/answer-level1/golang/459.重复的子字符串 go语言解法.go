### 解题思路

新建一个新字符串str=s+s，把str的首元素和尾元素去掉，剩下的部分如果还含有s，则返回true。

### 代码

```golang
func repeatedSubstringPattern(s string) bool {
	var str1 string = s + s
	var str2 string = str1[1:len(str1)-1]
	if strings.Contains(str2,s) {
		return true
	}else {
		return false
	}
}
```