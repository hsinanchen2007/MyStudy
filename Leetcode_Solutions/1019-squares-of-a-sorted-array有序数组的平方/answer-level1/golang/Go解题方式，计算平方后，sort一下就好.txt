func sortedSquares(A []int) []int {
```
 for i:=0;i<len(A);i++{
        A[i] = A[i]*A[i]
    }
    sort.Ints(A)
    return A
```}