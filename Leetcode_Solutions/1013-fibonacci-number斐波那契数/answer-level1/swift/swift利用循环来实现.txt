```
func fib(_ N: Int) -> Int {
    if N <= 1 {
        return N
    }
    var firstNum = 0
    var secondNum = 1
    var result = 0
    for _ in 2...N {
        result = secondNum + firstNum
        firstNum = secondNum
        secondNum = result
    }
    return result
}
```
