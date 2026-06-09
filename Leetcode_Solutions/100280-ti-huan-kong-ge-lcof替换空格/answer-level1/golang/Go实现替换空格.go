

```golang
func replaceSpace(s string) string {
    if s ==""{
        return ""
    }
    res := []rune{}
    for _,v := range s {
        if v ==  ' '{
            res = append(res,'%','2','0')
        }else{
            res = append(res,v)
        }
    }
    return string(res)
}
```

```
func replaceSpace(s string) string {
    if len(s)==0{
        return ""
    }
    res := ""
    for _,v:=range s{
        if v ==' '{
            res +="%20"
        }else{
            res+=string(v)
        }
    }
    return res
}
```
