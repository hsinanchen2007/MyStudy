### 解题思路
1、统计s中，每个字符出现的次数
2、遍历s，若发现某个字符（假设下标为i）出现次数少于k，则将问题分解为在左右两个substring进行递归处理
3、需要注意的时，右子串不是从i+1开始，而是从i下标之后，第一个满足count[s[j]]>=k的字符

### 代码
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2 MB, 在所有 Go 提交中击败了88.00%的用户
```golang
func longestSubstring(s string, k int) int {
    if len(s) < k {
        return 0
    }
    m := make(map[byte]int, 0)
    for i := 0; i < len(s); i++ {
        cnt,_ := m[s[i]]
        m[s[i]] = cnt+1
    }
    for i:=0; i < len(s);i++ {
        if cnt,_:= m[s[i]]; cnt < k {
            left := longestSubstring(s[:i],k)
            for j := i; j < len(s); j++ {
                //跳过多个连续不满足要求的字符
                if cntJ,_ := m[s[j]]; cntJ >= k{
                    return max(left, longestSubstring(s[j:],k))
                }
            }
            return left
        }
    }
    return len(s)
}

func max(a, b int) int {
    if a > b {
        return a
    }else{
        return b
    }
}
```