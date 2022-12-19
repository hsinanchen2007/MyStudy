![image.png](https://pic.leetcode-cn.com/fa74f17c972a814c1553832533573bdb5179525d9b3a1ddf5c10cb19d8001de4-image.png)


### 代码

```golang
var S string

func isNumber(s string) bool {
    e := "e"[0]

    // remove spaces on both side
    S = trim(s)

    // calculate the length of valid numbers
    S, pos := isNum(S)

    // all invalid
    if pos == 0 {
        return false
    }

    // get the remaining strings
    S = S[pos:]

    // no remaining, mean all valid
    if len(S) == 0 {
        return true
    }

    // first letter of remaining is `e`
    if S[0] == e {
        // checks if the string after e is an integer
        return isInt(S[1:])
    }

    return false
}

func trim(s string) string {
    spa := " "[0]

    l := len(s)
    i, j := 0, l - 1

    for ; j > 0; j-- {
        if s[j] != spa {
            break
        }
    }

    for ; i < j; i++ {
        if s[i] != spa {
            break
        }
    }

    return s[i:j + 1]
}

func removeSign(s string) string {
    pls := "+"[0]
    sub := "-"[0]

    if len(s) == 0 {
        return s
    }

    if s[0] == pls || s[0] == sub {
        return s[1:]
    }

    return s
}

func isNum(s string) (string, int) {
    dot := "."[0]
    ran := []byte{"0"[0], "9"[0]}
    e := "e"[0]

    s = removeSign(s)

    hasDot := false
    i := 0

    for ; i < len(s); i++ {
        // .
        if s[i] == dot {
            // more than one "."
            if hasDot {
                return s, 0
            } else {
                hasDot = true
                continue
            }
        }

        // in 0 ~ 9
        if s[i] >= ran[0] && s[i] <= ran[1] {
            continue
        }
        
        // e
        if s[i] == e {
            break
        }

        return s, 0
    }

    // just one "."
    if i == 1 && hasDot {
        return s, 0
    }

    return s, i
}

func isInt(s string) bool {
    ran := []byte{"0"[0], "9"[0]}

    s = removeSign(s)

    if len(s) == 0 {
        return false
    }

    for i := 0; i < len(s); i++ {
        // in 0 ~ 9
        if s[i] >= ran[0] && s[i] <= ran[1] {
            continue
        }

        return false
    }

    return true
}
```