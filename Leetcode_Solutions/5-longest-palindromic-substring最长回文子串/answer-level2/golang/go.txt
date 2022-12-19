### 解题思路
此处撰写解题思路

### 代码

```golang
func longestPalindrome(s string) string {
    if len(s)==0{
        return s
    }
    l,r:=0,0
    maxlen:=0
    for i:=0;i<len(s);i++{
        len1:=exten(s,i,i)
       len2:=exten(s,i-1,i)
        if maxlen<len1{
           l= i-len1/2
           r=i+len1/2
           maxlen=len1
        }
         if maxlen<len2{
            l= i-len2/2
           r=i-1+len2/2
           maxlen=len2
        }
    }
    return s[l:r+1]
}
func exten(s string, l int , r int)int{
    maxlen:=1
    for (l>=0 && r<len(s)) && s[l]==s[r]{
        maxlen=r-l+1
         r++
        l--
       
    }
    return maxlen
}
```