```
func add(a int, b int) int {
    var sum, carry int
    for {
        sum = a ^b
        carry = (a & b) <<1
        a = sum
        b = carry

        if b == 0 {
            return a
        }
    }   
}
```
