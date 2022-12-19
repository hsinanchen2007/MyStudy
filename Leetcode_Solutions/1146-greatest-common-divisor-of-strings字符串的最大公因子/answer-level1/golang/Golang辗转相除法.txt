### 解题思路
此处撰写解题思路

### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
    if str1 + str2 != str2 + str1 {
        return ""
    }
    var (
        f func(a,b int) int
        length int
    )
    f = func(a,b int)int {
        if b == 0 {
            return a
        }
        return f(b,a%b)
    }
    length = f(len(str1),len(str2))
    return str1[:length]
}
```