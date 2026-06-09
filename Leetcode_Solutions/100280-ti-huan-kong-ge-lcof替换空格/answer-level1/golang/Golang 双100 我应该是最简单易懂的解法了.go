func replaceSpace(s string) string {
    var tem string = "%20"
    for i := 0; i<len(s) ;i++ {
        if s[i] == ' ' {
            s = s[0:i] + tem + s[i+1:len(s)]
        }
    }
    return s
}