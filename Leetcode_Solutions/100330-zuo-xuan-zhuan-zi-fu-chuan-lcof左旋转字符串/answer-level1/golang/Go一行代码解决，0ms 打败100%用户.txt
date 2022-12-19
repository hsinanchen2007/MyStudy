### 解题思路

n为要截取字符串s的前n个字母，所以将要截取的两部分字符串拼接在一起返回结果即可。

### 代码

```golang
func reverseLeftWords(s string, n int) string {
    return s[n:len(s)] + s[:n]
}
```