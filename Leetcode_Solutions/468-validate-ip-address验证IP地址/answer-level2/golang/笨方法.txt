### 解题思路
此处撰写解题思路

### 代码

```golang
func validIPAddress(IP string) string {
    if strings.Contains(IP,".") && isV4(IP){
        return "IPv4"
    }
    if strings.Contains(IP,":") && isV6(IP){
        return "IPv6"
    }
    return "Neither"
}

func isV4(ip string)bool{
    parts := strings.Split(ip,".")
    if len(parts) != 4{
        return false
    }
    var firstPart int64
    for idx,s :=range parts {
        if (strings.HasPrefix(s,"0") && s != "0") || strings.Contains(s,"-"){
            return false
        }
 
        i,err := strconv.ParseInt(s,10,64)
        if err != nil{
            return false
        }
        if i > 1<<8-1 || i <0 {
            return false
        }
        if idx == 0{
            firstPart = i
        }
    }
    return firstPart!= 0
}
func isV6(ip string)bool{
    var firstPart int64
    parts := strings.Split(ip,":")
    if len(parts) != 8{
        return false
    }
    for idx,s :=range parts{
        if  len(s) ==0 || len(s) > 4{
            return false
        }
        if strings.Contains(s,"-"){
            return false
        }
        i,err := strconv.ParseInt(s,16,64)
        if err != nil{
            //fmt.Println(err)
            return false
        }
        //fmt.Println(i)
        if i > 1<<16-1 || i <0 {
            return false
        }
        if idx == 0{
            firstPart = i
        }
    }
    return firstPart!= 0
}
```