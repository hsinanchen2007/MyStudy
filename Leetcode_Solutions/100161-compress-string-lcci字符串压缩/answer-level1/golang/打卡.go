### 解题思路
暂无

### 代码

```golang
func compressString(S string) string {
    b := ""
    j:=1
    for i:=0;i<len(S);i = i + j {
        temp := S[i]
        j = 1
        for k:=i+1;k<len(S);k++ {
            if S[k] == temp {
                j++
            } else {
                break
            }
        }
        b = b + string(S[i]) + strconv.Itoa(j)
    }
    if len(b) >= len(S) {
        return S
    }
    return b
}
```