[暴力解法， 将所有配对括号替换为""
func isValid(s string) bool {  
    var length int
    for length != len(s){ 
        length = len(s)
        s = strings.Replace(s, "{}","", -1)
        s = strings.Replace(s, "()","", -1)
        s = strings.Replace(s, "[]","", -1)  
    }
    if len(s) > 0{
        return false
    }
    return true
}]()