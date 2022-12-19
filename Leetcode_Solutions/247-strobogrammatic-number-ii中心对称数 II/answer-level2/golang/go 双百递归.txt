### 解题思路
此处撰写解题思路

### 代码

```golang
func findStrobogrammatic(n int) []string {
    if n == 1{
        return []string{"0","1","8"}
    }
    if n == 2{
        return []string{"11","69","96","88"}
    }
    result := []string{}
    subs := helper(n-2)
    for _, sub := range subs{
        result = append(result, "1" +sub +"1")
        result = append(result, "6" +sub +"9")
        result = append(result, "9" +sub +"6")
        result = append(result, "8" +sub +"8")
    } 
    return result
}

func helper(n int) []string{
    if n == 1{
        return []string{"0","1","8"}
    }
    if n == 2{
        return []string{"11","69","96","88","00"}
    }
    result := []string{}
    subs := helper(n-2)
    for _, sub := range subs{
        result = append(result, "1" +sub +"1")
        result = append(result, "0" +sub +"0")
        result = append(result, "6" +sub +"9")
        result = append(result, "9" +sub +"6")
        result = append(result, "8" +sub +"8")
    } 
    return result
}
```