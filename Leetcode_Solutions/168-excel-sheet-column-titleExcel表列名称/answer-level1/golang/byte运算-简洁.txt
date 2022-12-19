### 解题思路
此处撰写解题思路

### 代码

```golang
func convertToTitle(n int) string {
    ans := []byte{}
    for ;n>0;n = n/26{
        n--
        ans = append([]byte{'A' + byte(n%26)},ans...)
    }
    return string(ans)
}
```