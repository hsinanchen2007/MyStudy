### 解题思路
用map记录滑动窗口中每个char的次数，与目标串的统计map做比较

### 代码

```golang
func check_map_equal(m1, m2 map[byte]int) bool {
    for k, v := range m1 {
        if m2[k] != v {
            return false
        }
    }
    return true
}

func checkInclusion(s1 string, s2 string) bool {
    if len(s1) > len(s2) {
        return false
    }
    m1 := make(map[byte]int)
    for i := 0; i < len(s1); i++ {
        m1[s1[i]] += 1
    }
    m2 := make(map[byte]int)
    for i := 0; i < len(s1); i++ {
        m2[s2[i]] += 1
    }
    if check_map_equal(m1, m2) {
        return true
    }

    for i := len(s1); i < len(s2); i++ {
        m2[s2[i]] += 1
        m2[s2[i-len(s1)]] -= 1
        if check_map_equal(m1, m2) {
            return true
        }
    }
    return false
}
```