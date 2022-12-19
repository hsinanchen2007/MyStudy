```go []
//最长公共整数
func longestCommonPrefix(strs []string) string {
	if  len(strs)==0 {
		return  ""
	}
	var j int
	var res string
	out: for {
		var tmp byte
		for i := 0; i < len(strs); i++ {
			if  j > len(strs[i])-1{
				break out
			}
			if i == 0 {
				tmp = strs[i][j]
			} else {
				if tmp != strs[i][j] {
               	    break out
				}
			}
		}
		res += string(tmp)
		j++
	}
	return res
}
```

