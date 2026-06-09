### 解题思路
开始遍历，只要遍历到的l和r相等的话，其实就可以匹配起来的

### 代码

```golang
func balancedStringSplit(s string) int {
    res,l,r := 0,0,0
    start := s[0]
    for i := range s {
        if s[i] == start {
            l++
        }else {
            r++
        }
        if l == r {
            res++
        }
    }
    
    return res
    
}
```