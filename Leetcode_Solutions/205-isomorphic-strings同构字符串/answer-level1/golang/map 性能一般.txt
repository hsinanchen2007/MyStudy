### Golang Hash
性能一般

### 代码

```golang
func isIsomorphic(s string, t string) bool {
    v1 := oneWay(s,t)
    v2 := oneWay(t,s)
    return v1 && v2
}

func oneWay(s ,t string)bool{
    temp := map[int32]int32{}
    for idx,sr := range s {
        k := int32(t[idx])
        v := int32(sr)
        //fmt.Println(temp,k,v)
        mv,ok := temp[k]
        if ok && mv != v{
            return false
        }else {
            temp[k] = v
        }
    }
    return true
}
```