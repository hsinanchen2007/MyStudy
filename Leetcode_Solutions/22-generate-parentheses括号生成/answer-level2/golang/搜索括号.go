### 解题思路
括号深搜

### 代码

```golang
var res []string
var buf []byte
func generateParenthesis(n int) []string {
    res=make([]string,0)
    buf=make([]byte,n*2)
    todo(n,n,0)
    return res
}
func todo(l,r,index int){
    if l+r==0{
        res=append(res,string(buf))
    }
    if l>0{
        buf[index]='('
        todo(l-1,r,index+1)
    }
    if r>0&&r>l{
        buf[index]=')'
        todo(l,r-1,index+1)
    }
}

```