# 字符串截取轻松返回
```
func reverseLeftWords(s string, n int) string {
    // 判断是否为0
    if n == 0 {
        return s
    }
    return s[n:len(s)] + s[0:n]
}
```
