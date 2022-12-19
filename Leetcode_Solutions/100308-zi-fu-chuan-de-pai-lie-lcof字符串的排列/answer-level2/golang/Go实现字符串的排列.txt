

```golang
func permutation(s string) []string {
    if len(s) == 0{
        return []string{}
    }
    res := []string{}
    st := []rune(s)
    chs := make([]string,0)
    for _,v := range st{
        chs = append(chs,string(v))
    }
    process(chs,"",&res)
    return res
}

func process(str []string,path string,res *[]string)[]string{
    if len(str) == 0{
        *res = append(*res,path)
    }
    m := make(map[string]int)
    for i:= 0;i<len(str);i++{
        if _, ok := m[str[i]]; !ok {
	    m[str[i]] = 1
        path1 := path+str[i]
        buf := make([]string,0)
        buf = append(buf,str[:i]...)
        buf = append(buf,str[i+1:]...)
        process(buf,path1,res)
        }
    }
    return *res
}
```