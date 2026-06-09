### 解题思路
思路很简单，就是利用map判断是否存在key值
```
执行用时 :0 ms, 在所有 Go 提交中击败了 100.00% 的用户
内存消耗 :1.9 MB, 在所有 Go 提交中击败了 100.00%的用户
```

### 代码

```golang
func isUnique(astr string) bool {
	var str = make(map[string]bool)
	for i := 0; i < len(astr); i++ {
		if _,ok:=str[string(astr[i])];ok{
			return false
		}
		str[string(astr[i])]=true
	}
	return true
}

```