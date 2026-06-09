### 解题思路
此处撰写解题思路

### 代码

```golang
func compressString(S string) string {
    if len(S) <= 1{
        return S
    }
    res := ""
    supportSlice := []byte{S[0]}
    for i := 1; i < len(S); i++{
        if S[i] != supportSlice[0]{
            res = res + string(supportSlice[0]) + strconv.Itoa(len(supportSlice))
            supportSlice = []byte{}
        }
        supportSlice = append(supportSlice,S[i])
    }
    res = res + string(supportSlice[0]) + strconv.Itoa(len(supportSlice))

    if len(res) < len(S){
        return res
    }
    return S
}
```