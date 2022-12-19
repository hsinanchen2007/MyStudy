### 解题思路
看见左括号就入栈，
看见右括号， 先判定栈是否为空，不为空就出栈做对比

+ 执行用时 : 0 ms, 在所有 golang 提交中击败了 100.00% 的用户
+ 内存消耗 : 2.1 MB, 在所有 golang 提交中击败了 30.99% 的用户

### 代码

```golang
func isValid(s string) bool {
    if len(s) % 2 == 1 {
        return false
    }

    stack := list.New()

    for i := 0; i < len(s); i++ {
        b := s[i]
        if (isJoin(b)) {
            stack.PushBack(b)
        } else {
            if stack.Len() == 0 {
                return false
            }
            be := stack.Back()
            bi := stack.Remove(be)
            if br, ok := bi.(byte); ok {
                switch br {
                    case '{': 
                        if b != '}' {
                            return false
                        }
                    case '[': 
                        if b != ']' {
                            return false
                        }
                    case '(': 
                        if b != ')' {
                            return false
                        }  
                }
            } else {
                return false
            }
        }
    }
    return stack.Len() == 0
    
}

// 是否入栈
func isJoin(b byte) bool {
    switch b {
        case '{', '[', '(': 
            return true
    }
    return false
}



/**
    压栈，出栈


*/
```