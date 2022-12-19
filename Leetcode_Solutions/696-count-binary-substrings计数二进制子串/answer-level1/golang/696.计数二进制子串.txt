### 解题思路

参考了官方题解，具体看注释。

### 代码

```golang
func countBinarySubstrings(s string) int {
	ans,prev,cur := 0,0,1	//prev子串为前半部分长度，cur为当前遍历的子串后一部分可能的长度
	for i := 1;i <len(s);i++ {
		if (s[i-1] != s[i]) {
			ans += min(prev, cur)	//因为子串前后两段一样长，所以取；两者中较小者
			prev = cur		//这个子串可能的后半部分，成为下一个子串的前半部分
			cur = 1			
		} else {
			cur++
		}
	}
	return ans + min(prev, cur)		//原字符串的最后一段不要忘记算上
}
func min(a int,b int) int {
	if a < b {
		return a
	}
	return b
}
```