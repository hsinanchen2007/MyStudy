### 解题思路
此处撰写解题思路

### 代码

```golang
func equalSubstring(s string, t string, maxCost int) int {
    if len(s) == 0 {
        return 0
    }

    left, right := 0, 0 

    sum,result := 0, 0
    for left <= right && right <= len(s)-1 {

        sum = sum + abs(s[right],t[right])
        //fmt.Println(abs(s[right],t[right]))
        for sum > maxCost {
            sum = sum - abs(s[left],t[left])
            left++ 
            if left > len(s)-1 {
                break
            }
        }
        result = max(result, right-left+1)
        right++
    }

    return result
}
func max(i,j int)int {
    if i > j {
        return i
    }
    return j
}
func abs(a,b byte) int {
    result := int(a)-int(b) 
    if result >0 {
        return result
    }
    return -result
}
```