索引最短string

```
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
            return ""
        }
        shortOne := strs[0]
        for _, s := range strs {
            if len(s) < len(shortOne) {
                shortOne = s
            }
        }
        for i:=0;i<len(shortOne);i++ {
            token := len(strs)
            for _, str := range strs {
                if str[i] == shortOne[i] {
                    token--
                }
            }
            if token != 0 {
                return shortOne[:i]
            }
            if token == 0 && i == len(shortOne)-1 {
                return shortOne
            }
        }
        return ""
}
```

![image.png](https://pic.leetcode-cn.com/0d4ececb025aacfbd664e632f6ae7255d1adb9133febc17e9ab9cd04c3760929-image.png)
