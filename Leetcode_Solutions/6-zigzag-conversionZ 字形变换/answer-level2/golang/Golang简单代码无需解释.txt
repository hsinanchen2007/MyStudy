
```golang
func convert(s string, numRows int) string {
    if numRows <2{
        return s
    }
    bss := make([][]byte,numRows)
    step,inc := 0,1
    for i:=0;i<len(s);i++{
        bss[step] = append(bss[step], s[i])
        if step == 0 {
            inc = 1
        }
        if step == numRows-1 {
            inc = -1
        }
        step = step + inc
    }
    ans := strings.Builder{}
    for _,bs := range bss {
        ans.Write(bs)
    }
    return ans.String()
}
```