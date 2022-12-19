[将右括号作为为hash key，然后遍历所有string，
如果是左括号，入栈，如果遇到右括号，出栈，检查右括号对应的左括号是否匹配；
如果遍历过程中发现栈为空但是出现右括号，也是不匹配，例如"]"
func isValid(s string) bool {  
    hash := map[rune]rune{']': '[', '}': '{', ')': '('}
    var stack []rune
    
    for _, v := range s{
        if _, ok := hash[v]; !ok{
            stack = append(stack, v)
        }else if len(stack) == 0 || hash[v] != stack[len(stack)-1]{
            return false
        }else{
            stack = append(stack[:len(stack)-1])
        }
      
    }
    
    if len(stack) != 0{
        return false
    }
    return true
}]()