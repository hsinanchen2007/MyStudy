### 解题思路
    用S中的字母进行遍历，用一个map,TMap记录该字母在T中出现的个数，拼接出S顺序的字符串str， 最后再将S中未出现的字母组成的字符串拼接到str的后面即可。 

### 代码

```golang
func customSortString(S string, T string) string {
    TMap := make(map[string]int, len(T))
    str := ""
    tempStr := ""
    for _, v := range T {
        //统计T中每个字母的个数
        TMap[string(v)]++
        //找到不在S中出现的T中的字母
        if strings.LastIndex(S, string(v)) < 0 {
            tempStr += string(v)
        }
    }
    //先处理在S中出现的字母
    for _, v := range S {
        for TMap[string(v)] > 0 {
            str += string(v)
            TMap[string(v)]--
        }
    }
    if tempStr != "" {
        str += tempStr
    } 
    return str
}
```