### 解题思路
去重->去子串->计算结果
### 代码

```golang
func minimumLengthEncoding(words []string) int {
    m := make(map[string]int, 0)
    // 去重
    for _, w := range words {
        if _, ok := m[w]; !ok {
            m[w] = 1
        }
    }
    // 去子串
    for _, w := range words {
        for i := 1; i < len(w); i ++ {
            delete(m, w[i:])
        }
    }
    // 计算结果
    ans := 0
    for k, _ := range m {
        ans += len(k) + 1
    }
    
    return ans
}
```