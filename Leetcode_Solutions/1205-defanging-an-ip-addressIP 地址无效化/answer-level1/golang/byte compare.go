### 解题思路
此处撰写解题思路

### 代码

```golang
func defangIPaddr(address string) string {
    n := len(address)
    ans := make([]byte,n+6)
    j:=0
    for i:=0;i<n;i++{
        bb := address[i]
        if bb == '.'{
            ans[j]='['
            ans[j+1]='.'
            ans[j+2]=']'
            j += 3
        }else{
            ans[j]= bb
            j++
        }
    }
    return string(ans)

}
```