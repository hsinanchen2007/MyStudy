### 解题思路
Go 双指针判断子字符串


### 代码

```golang
func findLongestWord(s string, d []string) string {
    res := ""
    for _, v:= range d {
        l1,l2:= len(res),len(v)
        if l1 > l2 || (l1==l2 && bytes.Compare([]byte(res),[]byte(v))<0) { 
            // 当前的长于下一个，或者相同长度但字典序小。continue
            // bytes.Compare 按字典序排序        
            continue
        }
        if isSubstr(s,v) {
            res = v
        }
    }
    return res
}
// 双指针判断是否是子串
func isSubstr (s, t string) bool {
    i, j := 0, 0
    byteS, byteT := []byte(s),[]byte(t)
    for i < len(s) && j < len(t) {
        if byteS[i] == byteT[j] {
            j++    
        }
        i++      //不相等跳过i
    }
    return j == len(t)
}
```