### 解题思路
首先将第一个字符串依次按照数字顺序入map，按照index为key，char为value来存放。
之后依次将所有的字符串依次与该map进行比较，取最小的匹配，
最后输入匹配即可

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }

    prefixMap := make(map[int]string)

    firstStr := strs[0]
    for index := 0; index < len(firstStr); index++ {
        s := string(firstStr[index])
        prefixMap[index] = s
    }

    prefixNum := len(firstStr)
    for i := 1; i < len(strs); i++ {
        str := strs[i]
        num := 0
        for j := 0; j < len(str); j++ {
            s := string(str[j])
            if prefixMap[j] == s {
                num++
            }else{
                break
            }
        }
        if num == 0{
            return ""
        }
        if num < prefixNum {
            prefixNum = num
        }
    }
    retStr := ""
    for i := 0;  i < prefixNum; i++ {
        retStr += prefixMap[i]
    }
    return retStr
}
```