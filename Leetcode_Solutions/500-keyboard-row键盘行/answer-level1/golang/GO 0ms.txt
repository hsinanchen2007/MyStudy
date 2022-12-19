```
func findWords(words []string) []string {
    var mmap = map[int]string{0:"qwertyuiop",1:"asdfghjkl",2:"zxcvbnm"}
    
    var result = []string{}
    for i := 0; i < len(words); i++ {
        if ok := judge(strings.ToLower(words[i]),mmap); ok {
            result = append(result, words[i])
        }
    }
    return result
    
}

func judge(s string, m map[int]string) bool {
    var mmap = map[int]int{0:0, 1:0, 2:0}  // 直接对键值对进行初始化
    // range 遍历字符串 v为字符类型
    // range可用于遍历切片、字符串 、map和数组  range是值拷贝，不会改变原来的变量的值
    for _, v := range s {
        if strings.ContainsRune(m[0], v) {
            mmap[0] += 1
            continue
        }
        if strings.ContainsRune(m[1], v) {
            mmap[1] += 1
            continue
        }
        mmap[2] += 1
    }
    flag := 0
    for _, v := range mmap {
        if v > 0 {
            flag += 1
        }
    }
    if flag >1 {
        return false
    }
    return true    
}
```