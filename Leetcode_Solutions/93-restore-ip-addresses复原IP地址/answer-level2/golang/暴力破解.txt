### 解题思路
此处撰写解题思路

### 代码

```golang
func restoreIpAddresses(s string) []string {
    n := len(s)
    if n<4 || n > 12{
        return nil
    }
    ans := []string{}
    list := []int{1,2,3}
    for _,dx := range list{
        if dx >n{
            continue
        }
        first := s[0:dx]
        if !valid(first) {
            continue
        }
        for _,dy :=range list{
            if dx +dy >n{
                continue
            }
            second := s[dx:dx+dy]
            if !valid(second){
                continue
            }
            for _,dz :=range list{
                if dx +dy +dz >n{
                    continue
                }
                third := s[dx+dy:dx+dy+dz]
                if !valid(third){
                    continue
                }
                for _,da :=range list{

                    if dx + dy +dz + da ==  n {
                        forth := s[dx+dy+dz:n]

                        //fmt.Println(first,second,third,forth)
                        if valid(forth){
                            ans = append(ans,fmt.Sprintf("%s.%s.%s.%s",first,second,third,forth))
                        }
                    }
                }
            }
        }
    }
    return ans
}

func valid(s string)( ok bool){
    if strings.HasPrefix(s,"0") && s != "0"{
        return false
    }
    i,err := strconv.ParseInt(s,10,64);
    if err != nil{
        return false
    }
    if i >= 0 && i<=255{
        return true
    }
    return false
}
```