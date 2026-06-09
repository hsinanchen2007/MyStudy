### 代码

```golang
func isValid(s string) bool {
    a :=make([]byte,len(s))
    var index int
    for i:=0;i<len(s);i++{
        if index<0{
            return false
        }
        switch s[i]{
            case ')':
                if index<=0||a[index-1]!='('{
                    return false
                }else {
                    index--
                }

            case']':
                if index<=0||a[index-1]!='['{
                    return false
                }else {
                    index--
                }
            case '}':
                if index<=0||a[index-1]!='{'{
                    return false
                }else {
                    index--
                }
            default :
                a[index]=s[i]
                index++ 
        }    
    }
    if index==0{
        return true
    }
    return false
}
```