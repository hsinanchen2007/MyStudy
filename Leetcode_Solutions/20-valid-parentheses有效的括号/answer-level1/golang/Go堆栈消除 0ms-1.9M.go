![QQ20200111-225454.png](https://pic.leetcode-cn.com/cd313b79452dc430217abb1b3cf7cd4dac71f74430297fdab60d188a21fb7601-QQ20200111-225454.png)

### 堆栈消除 [Go技术博客](https://mojotv.cn/go/golang-2fa)

### 代码

```golang
func isValid(s string) bool {
    stack := make([]byte,len(s))
    sln :=0
    for k := range s {
        sk := s[k]
        switch sk {
            case '(','[','{':
                stack[sln] = sk
                sln++
            case ')':        
                if sln >0 && stack[sln-1] == '(' {
                    sln--
                }else {
                    return false
                }
             case ']':        
                if sln >0 && stack[sln-1] == '[' {
                    sln--
                }else {
                    return false
                }
             case '}':        
                if sln >0 && stack[sln-1] == '{' {
                    sln--
                }else {
                    return false
                }
        }
    }
    return sln == 0
    
}
```