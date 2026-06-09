### 代码

```golang
func isMatch(s string, p string) bool {
    var match func(i,j int)bool
    match=func(i,j int)bool{
        if i>=len(s)&&j>=len(p){
            return true
        }else if i<len(s)&&j>=len(p){
            return false
        }else if j+1<len(p)&&p[j+1]=='*'{
            if  (i<len(s)&&s[i]==p[j])||(p[j]=='.'&&i<len(s)){
                return match(i+1,j)||match(i+1,j+2)||match(i,j+2)
            }else{
                return match(i,j+2)
            }
        }else if (i<len(s)&&s[i]==p[j])||(p[j]=='.'&&i<len(s)){
            return match(i+1,j+1)
        }
        return false
    }
    return match(0,0)
}
```