### 解题思路
统计出每个字符出现的次数，如果奇数的个数大于1个，肯定不是回文串


### 代码

```golang
func canPermutePalindrome(s string) bool {
    countMap := make(map[string]int)
    for _, temp := range strings.Split(s, "") {
        countMap[temp] = countMap[temp] + 1
    }
    oddCount := 0
    for _, count := range countMap {
        if count % 2 != 0 {
            oddCount = oddCount + 1
        }
    }
    if oddCount > 1{
        return false
    }
    return true
}
```