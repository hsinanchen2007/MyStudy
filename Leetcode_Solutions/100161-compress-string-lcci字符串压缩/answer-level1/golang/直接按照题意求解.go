### 解题思路
此处撰写解题思路

### 代码

```golang
import "strconv"
func compressString(S string) string {
    size := len(S)
    res := ""
    if size == 0 {
        return res
    }

    last := S[0]
    cnt := 1
    for i := 1; i < size; i++ {
        if S[i] != last {
            res += string(last) + strconv.Itoa(cnt)
            cnt = 1
            last = S[i]
        } else {
            cnt++
        }
    }
    res += string(last) + strconv.Itoa(cnt)
    if len(res) >= size {
        res = S
    }
    return res
}
```