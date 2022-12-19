思路比较简单，话不多说，直接看代码
```
func minIncrementForUnique(A []int) int {
    if len(A) == 0 {
        return 0
    }
    
    sort.Ints(A)
    res, value := 0, A[0]

    for i:=1; i<len(A); i++ {
        if A[i] <= value {
            value++
            res += value - A[i]
        } else {
            value = A[i]
        }
    }
    return res
}
```
