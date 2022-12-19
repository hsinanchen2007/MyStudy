

```golang
func add(a int, b int) int {
    sum := a
    for b!=0{
        sum = a^b
        b = (a&b)<<1
        a = sum
    }
    return sum
}
```