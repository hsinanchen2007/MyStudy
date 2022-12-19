```
func canThreePartsEqualSum(A []int) bool {
    var sum int
    for _, a := range A {
        sum += a
    }
    rest := sum % 3
    if rest != 0 {
        return false
    }
    dividedSum := sum / 3
    result := 0
    count := 0
    for _, a := range A {
        result = result + a
        if result == dividedSum {
            result = 0 
            count ++
        }
    }
    if result == 0 && count >= 3{
        return true
    }
    return false
}
```
