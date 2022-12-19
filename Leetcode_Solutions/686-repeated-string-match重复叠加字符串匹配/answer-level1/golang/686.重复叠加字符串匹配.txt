### 解题思路

（1）先用B长度除以A长度得出l，则可能的结果会在l，l+1，l+2中产生，否则是就是-1。
举个例子，若A="abcd",B="dabcdab",则l = 1，即最后的结果只会在1，2，3中产生，若叠加3次B还是不是子串，再叠加也不可能是了。
（2）循环判断A叠加几次，B才是字串
（3）返回结果，如果不存在返回-1

### 代码

```golang
func repeatedStringMatch(A string, B string) int {
	l := len(B) / len(A)
	tmp := strings.Repeat(A,l)
	for i := l;i <= l + 2;i++ {
		if strings.Contains(tmp,B) {
			return i
		}
		tmp += A
	}
	return -1

}
```