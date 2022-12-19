### 解题思路
此处撰写解题思路

### 代码

```golang
func restoreIpAddresses(s string) []string {
    result := make([]string, 0)
    backtrack(s, nil, &result)

    return result
}

func backtrack(s string, track []string, result *[]string) {
    if len(track)!=0 && ok(track[len(track)-1]) == false {
        return 
    }

    if len(s) > 0 && len(track) >= 4 {
        return 
    }

    if len(s) == 0 && len(track) == 4 {
        data := track[0] +"."+ track[1] +"."+ track[2] +"."+ track[3] 
        *result = append(*result, data)
        return 
    }

    length := 3
    if len(s) < 3 {
        length = len(s)
    }
    for i:=0; i < length; i++ { // 去重， 0开头
        if i != 0 && s[0] == '0'{
            break
        }
        scopy := s
        trackcopy := append([]string{}, track...)
        backtrack(scopy[i+1:], append(trackcopy, s[:i+1]), result)
    }
}

// 0-255
func ok(str string) bool {
    num, _ := strconv.Atoi(str) 

    if num >=0 && num <= 255 {
        return true
    }
    return false
}
```