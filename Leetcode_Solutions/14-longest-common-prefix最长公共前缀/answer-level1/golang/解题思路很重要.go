### 解题思路
此处撰写解题思路

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0{
        return ""
    }
    if len(strs[0])==0{
        return ""
    }
    minlen := len(strs[0])
	for i:=1; i<len(strs);i++{
		xlen := len(strs[i])
		if xlen < minlen{
            if xlen == 0{
                return ""
            }
			minlen = xlen
		}
	}
    i := 0
q:
    for ;i < minlen;i++{
        for j:=1;j < len(strs);j++{
            if strs[j][i] != strs[j-1][i]{
                break q
            }
        }
    }
    return strs[0][0:i]
}
```