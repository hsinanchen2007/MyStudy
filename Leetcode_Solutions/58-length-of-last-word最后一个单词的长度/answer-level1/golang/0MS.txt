func lengthOfLastWord(s string) int {
    if len(s) == 0{
        return 0
    }
    var ss string
    for i:=len(s)-1;i>=0;i--{
        if string(s[i]) != " " {
            ss = ss+string(s[i])
        }else{
            if len(ss) == 0{
                continue
            }else{
                break
            }
        }
    }
    n := len(ss)
    return n
}