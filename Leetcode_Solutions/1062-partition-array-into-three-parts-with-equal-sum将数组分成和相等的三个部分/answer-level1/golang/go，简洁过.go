思路基本都差不多，都是先算总和
```go
func canThreePartsEqualSum(A []int) bool {
    sum := 0
    for _, v := range A {
        sum += v
    }
    if sum % 3 != 0 {
        return false
    }
    average := sum / 3

    count := 0
    sum = 0
    for i:=0; i < len(A); i++ {
        sum += A[i]
        if sum == average {
            count++
            sum = 0
        }
    }
    
    // 如果是 [0,0,0,0,0] 可能大于3次
    return count >= 3
}
```

