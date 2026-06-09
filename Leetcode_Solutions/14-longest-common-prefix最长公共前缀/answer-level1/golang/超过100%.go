func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }

    one := strs[0]
    for i:=0;i<len(strs);i++{
        if len(strs[i])<len(one){
            one = strs[i]
        }
    }

    for i ,v := range one{
        for j:=0;j<len(strs);j++{
            if strs[j][i] != byte(v){
                return one[:i]
            }
        }
    }

    return one
}