
### 代码

```golang
func reverseLeftWords(s string, n int) string {
    return string([]byte(s)[n:])+string([]byte(s)[:n])
}
```