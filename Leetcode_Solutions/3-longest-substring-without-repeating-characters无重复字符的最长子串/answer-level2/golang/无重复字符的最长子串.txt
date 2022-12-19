### 解题思路
采用一个滑动窗口来计算无重复字符的最长子串

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    if s == "" {
        return 0
    }
    var hash map[byte]bool = make(map[byte]bool)
    var queue []byte
    var maxLen int
    for i := 0; i < len(s); i++ {
        _, exist := hash[s[i]]
        if !exist {
            queue = append(queue, s[i])
            if len(queue) > maxLen {
                maxLen = len(queue)
            }
        } else {
            for queue[0] != s[i] {
                delete(hash, queue[0])
                queue = queue[1:]
            }
            queue = queue[1:]
            queue = append(queue, s[i])
        }
        hash[s[i]] = true
    }
    return maxLen
}


// 动态规划（超时+超内存）
// List[i, j] 表示从i到j没有重复的长度
// List[i, j] = List[i, j - 1] + 1 if s[j] 不在List[i, j - 1]中
// List[i, j] = List[i, j - 1] s[j]在list[i, j - 1]中
// List[0, 0] = 1

// func lengthOfLongestSubstring(s string) int {
//     if s == "" {
//         return 0
//     }
//     list := make([][]int, len(s))
//     for i := 0; i < len(s); i++ {
//         list[i] = make([]int, len(s))
//         for j := i; j < len(s); j++ {
//             list[i][j] = 1
//         }
//     }
            
//     var maxLen = 1
//     for i := 0; i < len(s); i++ {
//         var hash map[byte]bool = make(map[byte]bool)
//         hash[s[i]] = true
//         for j := i + 1; j < len(s); j++ {
//             _, exist := hash[s[j]]
//             if exist {
//                 list[i][j] = list[i][j - 1]
//                 break
//             } else {
//                 list[i][j] = list[i][j - 1] + 1
//             }
//             if list[i][j] > maxLen {
//                 maxLen = list[i][j]
//             }
//             hash[s[j]] = true
//         }
//     }
//     return maxLen
// }
```