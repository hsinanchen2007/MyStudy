### 解题思路
先转成切片, 然后拼接返回

### 代码

```golang
func reverseLeftWords(s string, n int) string {
    rs := []rune(s)

    return string(append(rs[n:], rs[:n]...))
}
```