```golang
func countAndSay(n int) string {
    s := "1"
    for i:=0;i < n-1;i++ {
        s = read(s)
    }
    return s
}

func read(n string) string {
    s := []byte(n)
    result := ""
    curCount := 0
    l := len(s)
    for i:=0 ; i<l ; i++ {
        next := i + 1
        if next != l && s[i] == s[next] {
            curCount++
        }else{
            curCount++
            result += strconv.Itoa(curCount) + string(s[i])
            curCount = 0
        }
    }
    return result
}
```