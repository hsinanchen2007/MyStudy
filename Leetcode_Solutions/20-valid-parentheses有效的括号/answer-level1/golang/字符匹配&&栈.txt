```
func isValid(s string) bool {
    r := strings.NewReplacer("[]", "", "{}", "", "()", "")

    for newStr := r.Replace(s); newStr != ""; newStr = r.Replace(newStr) {
        if newStr == s {
            return false
        }
        s = newStr
    }
    return true
}
```

```
func isValid(s string) bool {
    pa := map[byte]byte{']': '[', '}': '{', ')': '('}
    matchStack := New()

    for i := 0; i < len(s); i++ {
        switch s[i] {
        case '[', '{', '(':
            matchStack.Push(s[i])
        case ']', '}', ')':
            if top, ok := matchStack.Peek().(byte); !ok {
                return false
            } else if pa[s[i]] == top {
                matchStack.Pop()
            } else {
                return false
            }
        default:
            return false
        }
    }

    if matchStack.Len() == 0 {
        return true
    }

    return false
}

type (
    Stack struct {
        top *node
        length int
    }
    node struct {
        value interface{}
        prev *node
    }
)
// Create a new stack
func New() *Stack {
    return &Stack{nil,0}
}
// Return the number of items in the stack
func (this *Stack) Len() int {
    return this.length
}
// View the top item on the stack
func (this *Stack) Peek() interface{} {
    if this.length == 0 {
        return nil
    }
    return this.top.value
}
// Pop the top item of the stack and return it
func (this *Stack) Pop() interface{} {
    if this.length == 0 {
        return nil
    }

    n := this.top
    this.top = n.prev
    this.length--
    return n.value
}
// Push a value onto the top of the stack
func (this *Stack) Push(value interface{}) {
    n := &node{value,this.top}
    this.top = n
    this.length++
}
```

