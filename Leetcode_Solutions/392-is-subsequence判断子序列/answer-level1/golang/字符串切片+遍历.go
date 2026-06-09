由于子串的顺序固定，所以每找到一个字符就可以将字符串t向后切片
```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for i in s:
            if t and i in t:
                flag = t.index(i)
                t = t[flag+1:]
            else:
                return False
        return True
```
go版本：
```
func isSubsequence(s string, t string) bool {
    for _, i := range s {
        tmp := strings.IndexRune(t, i)
        if tmp > -1 {
            t = t[tmp+1:]
        } else {
            return false
        }
    }
    return true
}
```
