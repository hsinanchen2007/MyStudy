### 解题思路
双指针，删除与增加等价

### 代码

```golang
func oneEditAway(first string, second string) bool {
    len1 := len(first)
    len2 := len(second)
    if len1 - len2 > 1 || len2 - len1 > 1 {
        return false
    }

    s1 := strings.Split(first, "")
    s2 := strings.Split(second, "")
    cnt := 0
    for i, j := 0, 0; i < len1 && j < len2; i, j = i+1, j+1 {
        if s1[i] != s2[j] {
            if len1 > len2 {
                j--
            } else if len1 < len2 {
                i--
            }
            cnt ++
        }

    }
    return cnt <= 1
}
```