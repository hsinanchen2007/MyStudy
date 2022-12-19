![image.png](https://pic.leetcode-cn.com/2ec8f8d57fa6d534ed356b9fdf36ca85dcc0813404b59c50928fdee2c16f99c2-image.png)

```
const BACKSPACE = 35

type StringStack struct {
    v []rune
}

func (this *StringStack) push (r rune) {
    if r == BACKSPACE {
        if  len(this.v) != 0 {
            this.v = this.v[:len(this.v) - 1]
        }
    } else {
        this.v = append(this.v, r)
    }
}


func (this *StringStack) toString() string {
    return string(this.v)
}

func backspaceCompare(S string, T string) bool {
    SS := StringStack{}
    
    for _, s := range S {
        SS.push(s)
    }
    
    ST := StringStack{}
    
    for _, s := range T {
        ST.push(s)
    }

    return SS.toString() == ST.toString()
}

func (this *StringStack) toString() string {
    return string(this.v)
}

func backspaceCompare(S string, T string) bool {
    SS := StringStack{}
    
    for _, s := range S {
        SS.push(s)
    }
    
    ST := StringStack{}
    
    for _, s := range T {
        ST.push(s)
    }

    return SS.toString() == ST.toString()
}
```
