### 解题思路
GO认为string是不可以修改的，采用byte转成可写的数组才可以操作

### 代码

```golang
func reverseLeftWords(s string, n int) string {
    r := []byte(s)
    l := len(s)
    if n > l{
        return string(r)
    }
    for i:= 0 ; i < l; i++{
        if i + n < l{
            r[i] =s[i + n]
        } else {
            r[i] = s[i + n - l]
        }
    }
    return string(r)
}
```