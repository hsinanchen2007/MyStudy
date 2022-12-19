### 解题思路
...

### 代码

```golang
func strStr(haystack string, needle string) int {
    lenH := len(haystack)
    lenN := len(needle)
    if lenN == 0{
        return 0
    }
    if lenN > lenH {
        return -1
    }
    for i:=0;i<lenH;i++{
        if haystack[i] == needle[0] {
            flag := true
            for j:= 1 ;j<lenN;j++{ 
                if (i+j>=lenH ) || haystack[i+j] != needle[j]  {
                    flag = false
                    break
                }
            }
            if flag  {
               return i 
            }
        }
    }
    return -1
}
```