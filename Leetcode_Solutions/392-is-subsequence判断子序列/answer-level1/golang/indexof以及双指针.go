### 解题思路
此处撰写解题思路

### 代码

```golang
func isSubsequence(s string, t string) bool {
    if s==""{
        return true
    }
	ls, lt := len(s), len(t)
	if ls>lt{
		return false
	}
	i,j:=0,0
	for i=0;i<ls&&j<lt;i++{
	    index:=strings.Index(t[j:],string(s[i]))
	    if index==-1{
			return false
		}else{
			j+=index+1
		}
	}
	return i==ls
}
```
```golang
func isSubsequence(s string, t string) bool {
	ls, lt := len(s), len(t)
	if ls>lt{
		return false
	}
	index1, index2 := 0, 0
	for index1 < ls && index2 < lt {
		if s[index1] == t[index2] {
			index1++
			index2++
		} else {
			if ls-index1>lt-index2{
				return false
			}
			index2++
		}
	}
	if index1==ls{
		return true
	}
	return false
}
```