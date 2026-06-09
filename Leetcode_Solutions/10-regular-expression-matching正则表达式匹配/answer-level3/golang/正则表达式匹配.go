### 解题思路
还是递归策略搞的，主要难度在*号的处理
另外有个测试用例比较极端，不做处理会陷入深度递归超时，所以先判断了最后一个字符是否匹配
执行用时 : 0 ms , 在所有 golang 提交中击败了 100.00% 的用户
内存消耗 : 2.1 MB, 在所有 golang 提交中击败了83.33% 的用户

### 代码

```golang
func cmp(s string, i int, p string, j int ) bool {
    //fmt.Println("i=",i," j=",j)
    if i==len(s) && j==len(p) {
       return true
    }
    
    if j >= len(p){
        return false
    }
    
    if (j+1 < len(p)) && (p[j+1] == '*') {
        if (i<len(s))&&((p[j] == s[i])||(p[j]=='.')) {
            if cmp(s,i+1,p,j+2) {
                return true
            }
            if cmp(s,i+1,p,j) {
                return true
            }
        }
        return cmp(s,i,p,j+2) 
        
    } else if (i<len(s))&&((p[j] == s[i])||(p[j]=='.')) {
        return cmp(s,i+1,p,j+1)
    }else {
        return false
    }
}
func isMatch(s string, p string) bool {
    if (len(p)>0)&&(len(s)>0)&&(p[len(p)-1] !='*')&&(p[len(p)-1] !='.')&&(p[len(p)-1]!=s[len(s)-1]) {
        return false
    }
    return  cmp(s,0,p,0)
}
```