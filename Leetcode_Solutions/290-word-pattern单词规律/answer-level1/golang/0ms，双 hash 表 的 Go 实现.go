
![image.png](https://pic.leetcode-cn.com/5144f3e4f7b6365f10cf37c0c65170dc6c55fd9794eee09775da5502a445d9e3-image.png)

```
func wordPattern(pattern string, str string) bool {
    str_arr := strings.Fields(str)
    if len(pattern)!=len(str_arr) {
        return false
    }
    hash := make(map[byte]string)
    hash2 := make(map[string]byte)
    for i:=0; i<len(pattern); i++ {
        v,ok := hash[pattern[i]]
        v2,ok2 := hash2[str_arr[i]]
        if ok && v!=str_arr[i] || ok2 && v2!=pattern[i] {
            return false
        } else {
            hash[pattern[i]] = str_arr[i]
            hash2[str_arr[i]] = pattern[i]
        }
    }
    return true
}
```