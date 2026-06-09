```
func longestOnes(A []int, K int) int {
    if len(A) == 0 {
        return 0
    }

    if len(A) <= K {
        return len(A)
    }
    
    low, high := 0, 0
    maxLength := K
    num := 0
    
    for high < len(A) {
        if A[high] == 0 {
            num++
        }
        for num > K {
            if A[low] == 0 {
                num--
            }
            low++
        }
        high++
        maxLength = int(math.Max(float64(maxLength), float64(high-low)))
    }
    return maxLength
}
```
