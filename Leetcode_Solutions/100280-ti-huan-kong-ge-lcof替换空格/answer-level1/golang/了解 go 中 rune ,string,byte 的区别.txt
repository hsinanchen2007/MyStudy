### 解题思路
go 语言中字符串是不能直接通过下标来访问的，在对字符串进行 for range遍历时，字符是 rune 类型。 string 类型底层是按字节存储的，所以一个字符可能是任意字节， rune 一个字符是4个字节。

### 代码

```golang
func replaceSpace(s string) string {
    ans := ""
    for _,v := range s{
        switch v{
            case ' ':
            ans = ans + "%20"
            default:
            ans = ans + string(v)
        }
    }
    return ans
}
```