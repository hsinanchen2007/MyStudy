双指针 复杂度O(n)

``` golang
func isSubsequence(s string, t string) bool {
    return method_point2(s, t)
}

//双指针 复杂度O(n)
func method_point2(s string, t string) bool {
    if len(s) > len(t) {
        return false
    }
    t1, t2 := 0, 0

    for t1 < len(s) && t2 < len(t) {
        if(s[t1] == t[t2]) {
            t1++
        }
        t2++
    }
    return t1 == len(s)
}
```
