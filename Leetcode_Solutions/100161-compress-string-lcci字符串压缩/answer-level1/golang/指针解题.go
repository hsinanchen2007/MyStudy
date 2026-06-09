思路：

通过指针指向第一个字符，用一个临时变量保存该字符，指针移动与临时变量比较，如果相同，统计数字+1，然后指针继续移动重复改过程

如果遇到不相等，重置累加值与临时变量的保存值

```golang
func compressString(S string) string {
    if len(S) == 0 {
        return S
    }

    result := ""
    tmp := ""
    i := 0
    for index, c := range S {
        if tmp == "" || tmp == string(c) { //数据相同，做累加
            tmp = string(c)
            i++
        } else {
            // 与上一个不相同
            result = fmt.Sprintf("%s%s%d", result,tmp, i)
            tmp = string(c)
            i = 1
        }
        if index == len(S) - 1 && tmp != "" {
            result = fmt.Sprintf("%s%s%d", result,tmp, i)
        }
    }
    if len(result) >= len(S) {
        return S
    }

    return result
}
```