### 解题思路

使用 bytes.Buffer 

### 代码

```golang
func replaceSpaces(S string, length int) string {
  var buffer bytes.Buffer
  for i:=0;i<length;i++{
    if S[i] != ' ' {
      buffer.WriteString(string(S[i]))
    } else {
      buffer.WriteString("%20")
    }
  }
  return buffer.String()
}
```