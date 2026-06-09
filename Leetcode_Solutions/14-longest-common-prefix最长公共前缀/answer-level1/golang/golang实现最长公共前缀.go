### 解题思路
1.先找出数组中最短的字符串short
2.然后用short做为比照对象与其他字符串进行比较

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    short := shortStr(strs)

    for i, v := range short {
        for j := 0; j < len(strs); j++ {
            if strs[j][i] != byte(v) {
                return strs[j][:i]
            }
        }
    }
    return short
}

func shortStr(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    res := strs[0]
    for _, v := range strs {
        if len(res) > len(v) {
            res = v
        }
    }
    return res
}
```