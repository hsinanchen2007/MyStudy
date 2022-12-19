### 代码

```golang
func firstUniqChar(s string) byte {
    if len(s)==0{
        return ' '
    }
    res,index:=byte(' '),0
    note:=map[byte]int{}
    for i:=0;i<len(s);i++{
        note[s[i]]++
        if res==' '&&note[s[i]]==1{
            res=s[i]
            index=i
        }else if s[i]==res{
            for j:=index+1;j<=i;j++{
                if j==i{
                    res=' '
                }else if note[s[j]]==1{
                    res=s[j]
                    index=j
                    break
                }
            }
        }
    }
    return res
}
```