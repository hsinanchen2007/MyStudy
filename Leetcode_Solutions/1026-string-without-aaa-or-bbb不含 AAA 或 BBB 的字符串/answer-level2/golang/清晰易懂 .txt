### 解题思路
A比B多  写上 AAB
B比A多  写上 BBA
一样多  写上 BA或者AB

一次写3个 那剩下2个或1一个怎么办呢
剩下2个一样多 会写AB 不会出错
两个A         会写AAB  B是多出来的最后去掉B （剩下一个同理）
反正最后写多了 丢掉后面的就行了 

有用点个赞 让我知道
### 代码

```golang
func strWithout3a3b(A int, B int) string {
	ww := A + B
	ans := ""
	for A > 0 || B > 0 {
		if A > B {
			ans += "aab"
			A -= 2
			B -= 1
		}
		if A < B {
			ans += "bba"
			A -= 1
			B -= 2
		}
		if A == B {
			ans += "ba"
			A -= 1
			B -= 1
		}
	}
	return ans[:ww]

}
```