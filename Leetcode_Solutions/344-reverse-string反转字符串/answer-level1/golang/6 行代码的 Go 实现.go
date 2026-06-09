头尾指针向中间遍历交换。

代码
```
func reverseString(s []byte)  {
    for i,j:=0,len(s)-1; i<j; {
        s[i],s[j] = s[j],s[i]
        i++;j--
    }
}
```