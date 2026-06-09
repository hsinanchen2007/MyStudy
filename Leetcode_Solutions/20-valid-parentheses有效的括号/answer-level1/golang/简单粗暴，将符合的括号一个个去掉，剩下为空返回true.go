### 解题思路
使用一个变量old存储替换前的string，替换后，若old=string，返回false ，若s=""返回true


### 代码

```golang
func isValid(s string) bool {
    for {
        old := s
        s = strings.Replace(s,"()","",-1)
        s = strings.Replace(s,"[]","",-1)
        s = strings.Replace(s,"{}","",-1)
        if s == "" {
            return true
        }
        if s == old {
            return false
        }
    }
    return false
}
```