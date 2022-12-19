### 解题思路

这道题我有点无语...跟比长度一样...

### 代码

```golang
func findLUSlength(a string, b string) int {
	if len(a) > len(b) {
		return len(a)
	} else if len(a) < len(b){
		return len(b)
	}
	if a == b {
		return -1
	}else {
		return len(a)
	}
}
```