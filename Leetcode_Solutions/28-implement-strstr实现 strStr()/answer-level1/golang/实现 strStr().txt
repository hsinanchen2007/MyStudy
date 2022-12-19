### 解题思路
得到首次字母在haystack中的所有位置，然后用haystack[位置：位置+len（needle）]是否等于needle,如果相等返回位置，不存在返回-1。如果needle的长度大于haystack的长度，这是肯定不存在的，返回-1。如果needle是空字符串，返回0。

### 代码

```golang
func strStr(haystack string, needle string) int {
    var num []int

    if len(needle)==0{
        return 0
    }else if len(haystack)<len(needle){
        return -1
    }

    for i:=0;i<len(haystack);i++{
        if haystack[i]==needle[0] {
            num=append(num,i)
        }
    }

    if len(num)==0{
        return -1
    }

    for i:=0;i<len(num);i++{
        if len(needle)+num[i] <= len(haystack) && haystack[num[i]:len(needle)+num[i]]==needle{
            return num[i]
        }
    }
    
    return -1

}
```