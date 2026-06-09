### 解题思路
此处撰写解题思路

### 代码

```golang
func cmp(m [][]int, s string, i int, p string, j int ) int {
   
    if(m[i][j]!=0){
        //fmt.Println("i=",i," j=",j," m=",m[i][j])
        return m[i][j]
    }
    //fmt.Println("i=",i," j=",j)
    if i==len(s) && j==len(p) {
       m[i][j] = 1
       return 1
    }
    
    if j >= len(p){
        m[i][j] = 2
        return 2
    }
    
    if (j+1 < len(p)) && (p[j+1] == '*') {
        if (i<len(s))&&((p[j] == s[i])||(p[j]=='.')) {
            if cmp(m,s,i+1,p,j+2) == 1 {
                m[i][j] = 1
                return 1
            }
            if cmp(m,s,i+1,p,j)==1 {
                m[i][j] = 1
                return 1
            }
        }
        m[i][j] = cmp(m,s,i,p,j+2)
        return  m[i][j]
        
    } else if (i<len(s))&&((p[j] == s[i])||(p[j]=='.')) {
        m[i][j] = cmp(m,s,i+1,p,j+1)
        return m[i][j]
    }else {
        m[i][j] = 2
        return 2
    }
}
func isMatch(s string, p string) bool {
    m := make([][]int, len(s)+1)
    for i := 0; i < len(s)+1; i++ {
        m[i] = make([]int, len(p)+1)
    }
    if (len(p)>0)&&(len(s)>0)&&(p[len(p)-1] !='*')&&(p[len(p)-1] !='.')&&(p[len(p)-1]!=s[len(s)-1]) {
        return false
    }
    if cmp(m, s,0,p,0) == 1 {
        return true
    }
    return  false
}
```