### 解题思路
1、设str=A*k,则len(str) <= len(B)+2\*len(A)
2、判断一个string c 是否为另一个string d 的子字符串 （参见subString函数）
将c中的每个字符映射到一个hash值，例如c[i]-'a'，然后将c每个字符的hash值相加。
这样在遍历d字符串的过程中，只需要挪动两个下标i，j，并且在挪动的过程中减去d[i]的值同时加上d[j]的值，然后判断d[i+1:j+1]的hash sum是否与预期相同，若相同，则判断d[i+1:j+1]是否与字符串c相同。
Rabin-Kaup Algorithm具体算法可参考YouTube：
https://www.youtube.com/watch?v=qQ8vS2btsxI
 

### 代码
执行用时 :16 ms, 在所有 Go 提交中击败了61.11%的用户
内存消耗 :8.7 MB, 在所有 Go 提交中击败了40.00%的用户

```golang

func repeatedStringMatch(A string, B string) int {
	str := A
	num := 0
	for i,_ := range B {
		num += int(B[i]-'a')
	}
	for len(str) < len(B)+2*len(A) {
		if subString(str, B, num) {
			return len(str)/len(A)
		}
		str += A
	}
	return -1
}

func subString(longStr, shortStr string, num int) bool {
	if len(longStr) < len(shortStr) {
		return false
	}
	n := len(shortStr)
	temp := 0
	for i := 0; i < n; i++ {
		temp += int(longStr[i]-'a')
	}
	if temp == num && longStr[:n] == shortStr {
		return true
	}
	for i := 0; i+n < len(longStr); i++ {
		j := i+n
		temp -= int(longStr[i]-'a')
		temp += int(longStr[j]-'a')
		if temp == num && longStr[i+1:j+1] == shortStr {
			return true
		}
	}
	return false
}
```