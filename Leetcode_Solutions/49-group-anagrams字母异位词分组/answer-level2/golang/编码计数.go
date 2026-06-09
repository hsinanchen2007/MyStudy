### 解题思路
参考官方题解，关键是编码函数的书写。

### 代码

```golang
func groupAnagrams(strs []string) [][]string {
    resultMap := map[string][]string{}
    for _, str := range strs {
        encodeResult := encode(str)
        resultMap[encodeResult] = append(resultMap[encodeResult], str)
    }

    result := make([][]string, 0)
    for _, v := range resultMap {
        result = append(result, v)
    }

    return result
}

func encode(input string) string {
    // 按照26位字符进行编码
    encodeSlice := make([]int, 26)
    for _, char := range input {
        encodeSlice[char - 'a']++
    }

    var buf bytes.Buffer
    for _, elem := range encodeSlice {
        buf.WriteString(strconv.Itoa(elem))
    }

    // 输出编码结果
    return buf.String()
}
```