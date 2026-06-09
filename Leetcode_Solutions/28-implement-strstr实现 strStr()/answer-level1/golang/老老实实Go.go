### 解题思路
从头遍历haystack, 遇到相同的记录c+1, 如果needle到底则全匹配. 
没到底继续往下走, 如果后面不一样了推倒重来, 跳回记录i-c, c也重置为0

### 代码

```golang
func strStr(haystack string, needle string) int {
    if len(needle) ==0 {
        return 0
    }
    var c = 0
    for i := 0; i < len(haystack); i++ { 
        s := haystack[i]
        if s == needle[c] {
            c++
            if len(needle) == c {
                return i-c + 1
            }
        } else{
            if c >0{
                i = i - c
                c = 0
            }
        }
    }
    return -1
}
```