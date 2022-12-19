```golang
func merge(A []int, m int, B []int, n int)  {
    A = append(A[:m],B[:n]...)
    sort.Ints(A)
}
```