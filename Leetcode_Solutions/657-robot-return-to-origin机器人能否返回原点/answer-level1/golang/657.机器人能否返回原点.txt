### 解题思路

只需判断U和D，L和R的数量是否相等即可，若相等返回true，否则false

### 代码

```golang
func judgeCircle(moves string) bool {
    tmp := make([]int,2)
    for i := 0;i < len(moves);i++ {
        if moves[i] == 'U' {
            tmp[0]++
        }
        if moves[i] == 'D' {
            tmp[0]--
        }
        if moves[i] == 'L' {
            tmp[1]++
        }
        if moves[i] == 'R' {
            tmp[1]--
        }
    }
    return tmp[0] == 0 && tmp[1] == 0
}
```