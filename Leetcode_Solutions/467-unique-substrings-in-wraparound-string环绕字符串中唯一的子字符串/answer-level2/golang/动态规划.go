### 解题思路
题目的关键信息是子串需要按照字符表有序，所以字母 d 结尾的子串中，如果去掉了 d 就是 c 结尾的子串集合，那么加上 d 之后，相比 c 结尾的子串集合，多了一个单独的 d ，所以 d 结尾的子串的数量就是 c 结尾子串数量加 1

### 代码

```golang
func findSubstringInWraproundString(p string) int {
    if(len(p) == 0) {
        return 0
    }
    record := make(map[byte]int, 0)
    dp := make([]int, len(p))
    dp[0] = 1
    record[p[0]] = 1
    for i := 1; i < len(p); i++ {
        interval := int(p[i]) - int(p[i-1])
        if interval == 1 || interval == -25 {
            dp[i] = dp[i-1] + 1
        } else {
            dp[i] = 1
        }
        record[p[i]] = maxInt(dp[i], record[p[i]])
    }
    answer := 0
    for _, v := range record {
        answer += v
    }
    return answer
}

func maxInt(a,b int) int {
    if a > b {
        return a
    }
    return b
}
```