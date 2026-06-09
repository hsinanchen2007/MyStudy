
```golang
func reverseWords(s string) string {
    if s == ""{
        return s
    }
    str := strings.Split(s," ")
    res := []string{}
    for i := len(str)-1;i>=0;i--{
        if len(str[i])!=0{
            res = append(res,str[i])
        }
    }
    a := strings.Join(res," ")
    return a
}
```