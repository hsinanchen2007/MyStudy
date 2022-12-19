return(strings.Replace(address,".","[.]",-1))
↑ 其中-1代表全部替换

↓ 文档：
> func Replace(s, old, new string, n int) string
> If n < 0, there is no limit on the number of replacements.