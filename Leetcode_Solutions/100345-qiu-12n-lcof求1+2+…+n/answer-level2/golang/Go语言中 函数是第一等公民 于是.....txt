```
func plus_eq(a *int, b int) bool {
    *a += b
    return true
}

func sumNums(n int) int {
        _ = n > 0 && plus_eq(&n, sumNums(n - 1)) // 等于 n += sumNum(n - 1)
        return n
}
```


不够骚?

```
var sum = 0

func accumulator(memo int) func(int) int {
    return func(n int) int {
        memo += n
        return memo
    }
}

func rec(n int, acc func(int) int) bool {
    sum = acc(n)
    _ = n != 0 && rec(n - 1, acc)
    return true
}

func sumNums(n int) int {
    rec(n, accumulator(0))
    return sum
}
```

您细品(滑稽)
