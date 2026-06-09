### 解题思路
双指针倒排
### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    a := m - 1
    b := n - 1
    for {
        if a >= 0 && b >= 0 {
            if B[b] >= A[a] {
                A[a + b + 1] = B[b]
                b--
            } else {
                A[a + b + 1] = A[a]
                a--
            }
        } else {
            break
        }
    }

    for {
        if b >= 0 {
            A[b] = B[b]
            b--
        } else {
            break
        }
    }
}
```