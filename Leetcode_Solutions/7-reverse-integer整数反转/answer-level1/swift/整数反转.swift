官方解法:

```Swift
func reverse(_ x: Int) -> Int {
    var rev: Int = 0
    var helpX = x
    while helpX != 0 {
        let pop = helpX % 10
        helpX = helpX / 10
        
        if (rev > Int32.max / 10) || ((rev == Int32.max / 10) && pop > 7) {
            return 0
        }
        if (rev < Int32.min / 10) || ((rev == Int32.min / 10) && pop < -8) {
            return 0
        }
        
        rev = rev * 10 + pop
    }
    
    return rev
}
```

    其中对应的 32位 Int 最大和最小值用 math 库中 Int32.max 和 Int32.min 表示.