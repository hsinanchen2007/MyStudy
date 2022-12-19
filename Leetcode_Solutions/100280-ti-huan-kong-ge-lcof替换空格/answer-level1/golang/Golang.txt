### 代码

```golang
func replaceSpace(s string) string {
    res:=""
    for i:=0;i<len(s);i++{
        if s[i]==' '{
            res+="%20"
        }else{
            res+=string(s[i])
        }
    }
    return res
}
```