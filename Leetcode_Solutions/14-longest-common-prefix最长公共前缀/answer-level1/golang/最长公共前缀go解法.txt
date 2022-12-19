### 解题思路
此处撰写解题思路

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    } else if len(strs) == 1 {
        return strs[0]
    }
    first := strs[0]
    pre := ""
    for i:=0; i<len(first); i++ {
        for _, str := range strs[1:] {
            if i>len(str)-1 || str[i] != first[i] {
                return pre
            }
        }
        pre += string(first[i])
    }
    return pre
}
```