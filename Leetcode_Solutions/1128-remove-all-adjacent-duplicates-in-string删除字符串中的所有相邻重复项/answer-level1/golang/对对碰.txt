### 解题思路
此处撰写解题思路
跟着逻辑走
### 代码

```golang
func removeDuplicates(S string) string {
    
	if len(S) < 1 || len(S) > 20000{
		return ""
	}

	rs := []rune(S)

    i:= 0
	for i<len(rs) - 1{
		if rs[i] == rs[i+1]{
			rs = append(rs[:i],rs[i+2:]...)
            if i >= 1{
                i--
            }
            continue
		}
        
        i++
	}
     
	return string(rs)
}
```