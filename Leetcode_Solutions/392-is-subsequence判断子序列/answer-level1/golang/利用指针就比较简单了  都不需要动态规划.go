### 解题思路
利用双指针会比较简单  动态规划会过于复杂

### 代码

```golang
func isSubsequence(s string, t string) bool {
	ls,lt := len(s),len(t)
    if ls == 0{
		return true
	}
	if lt == 0 || lt < ls{
		return false
	}
  
	p := 0
	for i:=0;i<lt;i++{
		if s[p] == t[i]{
			p++
			if p == ls{
				return true
			}
		}
	}
	return false
}
```