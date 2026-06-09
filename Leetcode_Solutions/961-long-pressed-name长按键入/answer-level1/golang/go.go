### 解题思路
此处撰写解题思路

### 代码

```golang
func isLongPressedName(name string, typed string) bool {
    cur := name[0]
    for len(typed) > 0 && len(name) > 0{
        if name[0] == typed[0]{
            cur = name[0]
            name = name[1:]
            typed = typed[1:]
        }else if typed[0] == cur{
            typed = typed[1:]
        }else{
            return false
        }
    }
    for len(typed) > 0{
        if typed[0] == cur{
            typed = typed[1:]
        }else{
            return false
        }
    }
    return len(name) == 0
}
```