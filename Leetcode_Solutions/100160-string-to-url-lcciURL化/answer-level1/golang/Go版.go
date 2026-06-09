### 解题思路
先截取前N位，再进行全替换

### 代码

```golang
func replaceSpaces(S string, length int) string {
    S = S[:length]
    S = strings.ReplaceAll(S, " ", "%20")
    return S
}
```