### 解题思路
此处撰写解题思路

### 代码

```golang
func isValid(s string) bool {
    var c []string
    m := map[string]string{
        ")":"(",
        "}":"{",
        "]":"[",
    }
    for _,v := range s {
        l := len(c)
        if l > 0 {
            if _,ok := m[string(v)]; ok {
                if c[l-1] == m[string(v)]{
                c = c[:l-1]
                continue
                }
            }
        }
        c = append(c,string(v))
    }
    return len(c)==0
}
```