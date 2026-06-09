使用索引法
```
func lengthOfLongestSubstring(s string) int {
    if len(s) == 0 {
        return 0
    }
    var maxlens int
    n := len(s)
    
    var index = make([]int, 256)
    for i,j:=0,0; j < n; j++{
        i = If(index[s[j]] > i, index[s[j]], i).(int)
        maxlens = If(maxlens > (j-i+1), maxlens, j-i+1).(int)
        index[s[j]] = j+1
    }
    return maxlens
}

func If(condition bool, truevalue, falsevalue int) interface{}{
    if condition{
        return truevalue
    }else{
        return falsevalue
    }
}
```
