
```golang []
func isValid(s string) bool {
    stack := []rune{}
    dict := map[rune]rune{')': '(', ']': '[', '}': '{'}
    for _, c := range s{
        if dict[c] == 0{
            stack = append(stack, c)
        }else if len(stack) > 0 && stack[len(stack) - 1] == dict[c]{
            stack = stack[: len(stack) - 1]
        }else{
            return false
        }
    }
    return len(stack) == 0
}
```
![image.png](https://pic.leetcode-cn.com/97538683a76155a00e9e45c01ceacb5c9adacff8a5236721e90599ebc0e1e164-image.png)

