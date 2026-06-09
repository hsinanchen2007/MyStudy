使用哈希表有效减少条件语句 


       var index = s.startIndex
        var stack = [Character]()
        
        var pair:[Character: Character] = ["[":"]","{":"}","(":")"]
        
        while index != s.endIndex {
            switch s[index] {
            case "[","{","(": stack.append(s[index])
            case "]","}",")":
               
               guard !stack.isEmpty, pair[stack.removeLast()] == s[index] else {
                return false
                }
            default:
                break
            }
            index = s.index(after: index)
        }
        
        return stack.isEmpty