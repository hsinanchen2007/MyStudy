从前向后遍历，需要不停移动A中元素。从后向前，不需要移动。当A遍历完，且B没有遍历完，需要把B中元素移到A中。

```
func merge(A []int, m int, B []int, n int)  {
    pos := m + n - 1
    m--
    n--
    for m >= 0 && n >= 0 {
        if A[m] > B[n] {
            A[pos] = A[m]
            m--
        } else {
            A[pos] = B[n]
            n--
        }
        pos--
    }
    for n >= 0 {
        A[pos] = B[n]
        n--
        pos--
    }
}
```
