func compressString(S string) string {
    if len(S) == 0{
        return S
    }
    s1 := []byte{}
    for i, j :=0, 1; i < len(S); i++{
        if i+1 != len(S) && S[i] == S[i+1]{
            j++
        }else {
            s1 = append(s1,S[i])
            s1 = append(s1,strconv.Itoa(j)...)
            j = 1
        }
    }
    if len(s1) >= len(S){
        return S
    }
    return string(s1)
}