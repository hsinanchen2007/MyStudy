### 代码

```golang
var res []string
func generateParenthesis(n int) []string {
    s:=make([]byte,n*2)
    res=make([]string,0)
    todo(0,0,n*2-1,true,s)
    return res
}

func todo(k,num,n int,ok bool,s []byte){
    if ok {
        s[k]='('
        num++
    }else{
        s[k]=')'
        num--
    }
    if num<0||(num-1)*2>n{
        return
    }
    if k==n{
        if num==0{
            res=append(res,string(s))
        }
        return
    }
    todo(k+1,num,n,true,s)
    todo(k+1,num,n,false,s)
}
```