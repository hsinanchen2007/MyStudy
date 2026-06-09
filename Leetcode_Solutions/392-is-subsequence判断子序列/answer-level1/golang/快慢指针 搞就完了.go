### 解题思路
此处撰写解题思路

### 代码

```golang
func isSubsequence(s string, t string) bool {

    if len(s) > len(t) {
        return false
    }
    if len(s) == 0 {
        return true
    }

    slow := 0

    for fast := 0; fast < len(t); fast++ {
        if s[slow] == t[fast] {
            slow++
            if slow == len(s) {
                return true
            }
        }
    }
    return false
}
```