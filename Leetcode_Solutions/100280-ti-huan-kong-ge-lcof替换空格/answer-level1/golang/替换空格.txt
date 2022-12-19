### 解题思路
从尾向头遍历替换。

### 代码

```golang
func replaceSpace(s string) string {
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 32 {
            s = s[:i] + "%20" + s[i+1:]
        }
    }
    return s
}
```