```
func isValid(s string) bool {
    if len(s) == 0 {
        return true
    }
    m := make(map[string]string)
    m[")"] = "("
    m["}"] = "{"
    m["]"] = "["
    arr := strings.Split(s, "")
    if arr[0] == ")" || arr[0] == "}" || arr[0] == "]"{
        return false
    }
    temp := []string{arr[0]}
    for i:= 1;i<len(arr);i++ {
        if len(temp) == 0 {
			temp = append(temp, arr[i])	
			continue
		}
        if m[arr[i]] == temp[len(temp)-1] {
            temp = temp[:len(temp)-1]
        }else {
            temp = append(temp, arr[i])
        }
    }
    return len(temp) == 0
}
```
