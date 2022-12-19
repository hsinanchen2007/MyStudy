### 解题思路
此处撰写解题思路
count 记录L R count为0分割一次
令 L 为增1  R为 -1

### 代码

```golang
func balancedStringSplit(s string) int {
    if len(s) < 2 {
        return 0
    }

    res := 0
    count := 1
    if s[0] == 'R' {
        count = -1
    }
    
    for i := 1; i < len(s); i++ {
        if 'R' == s[i] {
            count--
        }else if  'L' == s[i]{
            count++
        }
        if count == 0 {
            res++
        }
    }

    return res
}
```