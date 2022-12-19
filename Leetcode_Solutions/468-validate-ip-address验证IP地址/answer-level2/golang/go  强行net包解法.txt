### 解题思路
此处撰写解题思路
net.ParseIP 之后 再判断
### 代码

```golang
import(
    "net"
    "strings"
)
func validIPAddress(IP string) string {
    
    ip := net.ParseIP(IP)
    if ip != nil{
        if ip.To4() !=nil {
            if ip.String() != IP {
                return "Neither"
            }
            return "IPv4"
        }
        temp := strings.Split(IP, ":")
        for i := range temp {
            if len(temp[i]) > 4 || len(temp[i]) == 0 {
                return "Neither"
            } 
        }
        return "IPv6"
    } 
    return "Neither"
}
```