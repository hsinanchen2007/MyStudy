### 解题思路
时间和内存消耗的高的一匹，巨垃圾

### 代码

```golang
func reverseWords(s string) string {
    var res string
    var ans []string
    ans = strings.Fields(strings.TrimSpace(s))
    for i := len(ans)-1; i >= 0; i--{
        fmt.Println(ans[i])
        res = res + " " + ans[i]
    }
    res = strings.TrimSpace(res)
    return res
}
```