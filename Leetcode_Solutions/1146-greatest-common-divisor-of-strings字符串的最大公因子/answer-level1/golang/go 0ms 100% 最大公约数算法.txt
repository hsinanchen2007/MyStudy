### 解题思路
此处撰写解题思路

### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
    if str1 + str2 != str2 + str1 {
        return ""
    }
    a, b := len(str1), len(str2) 
    if a < b {
        a, b = b, a
    } 
    for c := a % b; c != 0; c = a % b  {
        a, b = b, c
    }
    return str1[:b]
}
```