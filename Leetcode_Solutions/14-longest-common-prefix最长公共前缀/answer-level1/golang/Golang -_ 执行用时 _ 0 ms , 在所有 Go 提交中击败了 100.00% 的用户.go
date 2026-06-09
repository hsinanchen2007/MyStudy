### 解题思路
1. 先loop一遍所有的strs得到最短str ->shortestLength
2. 从所有strs的index 0开始比对，出现不同即返回result string；如果相同将相同的char 拼接到result string的尾部
3. 返回result string

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    result := ""
    lastChar := ""
    shortestLength := getShortestString(strs)

    for j := 0; j < shortestLength; j++ {
        for i := 0; i < len(strs); i++ {
            if len(strs[i]) <= j {
                return result
            }
            if i == 0 {
                lastChar = string(strs[i][j])
            }
            if string(strs[i][j]) != lastChar {
                return result
            }
            if i == len(strs) - 1 {
                result += lastChar
            }
        }
    }
    return result
}

func getShortestString(strs []string) int {
    shortestLength := math.MaxInt32
    for i := 0; i < len(strs); i++ {
        if len(strs[i]) < shortestLength {
            shortestLength = len(strs[i])
        }
    }
    return shortestLength
}
```
### 复杂度分析
时间复杂度：O(n) 其中n为所有string的char总个数
空间复杂度：O(1) 常数级别的额外空间string来存储