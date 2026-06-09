1. 解题思路：
    哈希表；
2. 数组的长度
    注意数组的长度，如果只考虑小写字母就 26 了，考虑大写字母的话，z - A + 1;
3. 切片初始化的两种方式：
```
chs := make([]byte, 1, 1)

var chs [1]byte

```
4. 代码实现

```
func countCharacters(words []string, chars string) int {
    if len(words) == 0 {
        return 0
    }

    // 构建字符哈希表
    chs := make([]byte, 'z'-'A'+1)
    for _, ch := range chars {
        chs[ch-'A']++
    }
    
    // 初始化长度之和
    res := 0

    // 遍历字符串数组
    for _, str := range words {
        if isContained(str, chs) {// 如果包含
            res = res + len(str)
        }
    }
    return res
}

func isContained(str string, chs []byte) bool {

    ws := make([]byte, 'z'-'A'+1)
    for _, w := range str {
        ws[w-'A']++
    }
    // 一一比较两个哈希表的元素
    for i := 0; i < len(ws); i++ {
        if len(ws) > len(chs) {
            return false
        }
        if ws[i] > chs[i] {
            return false
        }
    }
    return true
}
```
