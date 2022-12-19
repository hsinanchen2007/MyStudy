当某一个长度为$x$的子串(假定是$s[i...j]$)出现次数为$n$, 必然存在长度为$x-1$的子串($s[i+1...j]$ 或 $s[i...j-1]$) 出现次数不小于$n$, 所以只求$minSize$的情况即可.

Ps: 主要是贴下`GOLANG`的代码..hhh.

```go
func max(a, b int) int { // Go还得自己写比较大小qaq.
    if a>b {
        return a
    } else {
        return b
    }
}

func check(s string, mx int) bool {  // 这部分在Go里有优雅的方式嘛, 自己写怪麻烦的.
    var vis [33]bool
    sum := 0
    for _, v := range s {
        if vis[(int)(v-'a')] {
            continue
        }
        sum ++
        vis[(int)(v-'a')] = true
    }
    return sum <= mx
}

func maxFreq(s string, maxLetters int, minSize int, maxSize int) int {
    ans := 0
    ls := len(s)

    m := make(map[string]int)
    for i:=minSize; i<=ls; i++ {
        ss := s[i-minSize:i]
        if !check(ss, maxLetters) {
            continue
        }
        v, ok := m[ss]
        if ok {
            m[ss] = v+1
        } else {
            m[ss] = 1
        }
        ans = max(ans, m[ss])
    }

    return ans
}
```
