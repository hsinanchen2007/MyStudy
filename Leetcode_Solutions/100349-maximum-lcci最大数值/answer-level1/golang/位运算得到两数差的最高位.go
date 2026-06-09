```
func maximum(a int, b int) int {
    // a-b 如果为整数则a>b,反之则a<b
    // a>b 最高位位0，反之为1
    v := uint64(a-b)>>63
    // 如果 v=0,则1^v=1
    // 如果 v=1,则1^v=0
    return int(v)*b + int(1^v)*a
}
```
