

* 利用 栈 处理此问题

* 解题思想:
    * 这题其实很简单, 不要被 Hard 的 title 吓到了, 利用 栈 来检查标签没杀好说的, 注意审题和一些小的 Case
        * 一定注意题目的第一个要求, 整个字符串, 必须开头和结尾由是一对TAG, 而且整个字符串被这个 TAG包裹... , 例如 `<A></A><B></B>` 的结果是 False, 例如 `<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>` 的结果, 也是 false
        * 注意数组越界的问题

* 时间复杂度: O(n)
* 空间复杂度: O(1)


* 祝你顺利 Pass

```

import (
    "unicode"
)

type status struct {
    startTag string // 长度范围位于 1 - 9
}

func isValid(code string) bool {
    if !checkHeadAndTail(code) {
        return false
    }
    stack := make([]status, 0)
    
    now := status{}
    for i := 0; i < len(code); i++ {
        switch {
        case code[i] == '<' && i+1 < len(code) && code[i+1] == '!': // CDATA 标签
            i += 2
            if len(code)-1-i < 9 {
                return false
            } else if code[i:i+7] != "[CDATA[" {
                return false
            } else {
                i += 7
                stack = append(stack, status{startTag: "CDATA"})
            }
            
            for ; i < len(code); i++ {
                if code[i] == ']' && i+2 <= len(code)-1 && code[i+1] == ']' && code[i+2] == '>' {
                    stack = stack[0 : len(stack)-1]
                    i += 2
                    break
                }
            }
        
        case code[i] == '<' && i+1 < len(code) && code[i+1] == '/': // 结束 标签
            if len(stack) == 0 {
                return false
            }
            i += 2
            endTag := ""
            for ; i < len(code); i++ {
                if code[i] == '>' {
                    if endTag != stack[len(stack)-1].startTag {
                        return false
                    } else {
                        stack = stack[0 : len(stack)-1]
                        break
                    }
                } else {
                    if !unicode.IsUpper(rune(code[i])) {
                        return false
                    }
                    endTag += string(code[i])
                }
                
            }
        
        case code[i] == '<': // start tag 或者意外结束
            i++
            for j := 0; i < len(code); i++ {
                if code[i] == '>' {
                    if j < 1 || j > 9 {
                        return false
                    }
                    stack = append(stack, now)
                    now = status{}
                    break
                } else {
                    if !unicode.IsUpper(rune(code[i])) {
                        return false
                    }
                    now.startTag += string(code[i])
                    j++
                }
            }
        }
    }
    
    return len(stack) == 0
    
}
func checkHeadAndTail(code string) bool {
    head, tail := "", ""
    
    for i := 1; i < len(code); i++ {
        if code[i] == '>' {
            break
            
        } else {
            head += string(code[i])
        }
    }
    
    for i := len(code) - 2; i >= 0; i-- {
        if code[i] == '/' {
            break
        } else {
            tail = string(code[i]) + tail
        }
    }
    
    return head == tail
}
```


执行用时 :4 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2 MB, 在所有 Go 提交中击败了100.00%的用户