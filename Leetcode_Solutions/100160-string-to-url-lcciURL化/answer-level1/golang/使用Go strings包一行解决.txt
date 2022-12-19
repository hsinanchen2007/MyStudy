### 解题思路

先确定字符串长度，再替换。  

### 代码

```golang
func replaceSpaces(S string, length int) string {
    return strings.Replace(S[:length]," ","%20",-1)
}
```