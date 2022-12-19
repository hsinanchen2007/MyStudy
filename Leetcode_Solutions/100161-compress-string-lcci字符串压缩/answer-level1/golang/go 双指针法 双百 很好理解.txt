### 解题思路
双指针思路
指针i指向第一个要检测的字符, 用strings.Builder记录新字符串
指针j=i+1, if S[i]!=S[j], 写入字符串S[i],数量等于j-i，然后下次检测从j开始，也即i=j
如果j到达字符串尾部, 那么只需要再次 写入字符串S[i],数量等于j-i
最后比较一下新旧长度，如果新的短就返回新的，否则返回旧的
 

### 代码

```golang
func compressString(S string) string {
    var res strings.Builder
    for i := 0; i < len(S); {
        j := i + 1
        for j < len(S) {
            if S[i] != S[j] {
                res.WriteByte(S[i])
                res.WriteString(strconv.Itoa(j-i))
                i = j   // next char
            }
            j++
        }
        if j == len(S) {
            res.WriteByte(S[i])
            res.WriteString(strconv.Itoa(j-i))
            break
        }
    }
    if res.Len() >= len(S) {
        return S
    }
    return res.String()
}
```